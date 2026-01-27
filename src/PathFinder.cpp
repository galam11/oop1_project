#include "PathFinder.h"
#include "Board.h"
#include <queue>
#include <map>
#include <cmath>

sf::Vector2i PathFinder::findNextStep(const sf::Vector2i& start, const sf::Vector2i& target, const Board& board)
{
    if (start == target) return start;

    // A* Open Set
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;

    // Use maps because we don't know the grid size anymore (Encapsulation!)
    std::map<sf::Vector2i, int, Vec2Comparator> gScore;
    std::map<sf::Vector2i, sf::Vector2i, Vec2Comparator> parent;

    // Initialize start
    gScore[start] = 0;
    openSet.push({ start, 0, std::abs(target.x - start.x) + std::abs(target.y - start.y) });

    while (!openSet.empty())
    {
        Node curr = openSet.top();
        openSet.pop();

        // If we found target (or close enough if you wanted to add loose logic)
        if (curr.pos == target)
        {
            sf::Vector2i pathNode = curr.pos;
            // Backtrack to find the very first step
            while (parent.count(pathNode) && parent[pathNode] != start) {
                pathNode = parent[pathNode];
            }
            return pathNode;
        }

        // --- THE KEY CHANGE ---
        // We now ask the Board for valid neighbors, we don't calculate them here.
        for (const auto& neighbor : board.getValidNeighbors(curr.pos))
        {
            int tentativeG = gScore[curr.pos] + 1;

            // If this path to neighbor is better, or we haven't seen it yet
            if (gScore.find(neighbor) == gScore.end() || tentativeG < gScore[neighbor])
            {
                parent[neighbor] = curr.pos;
                gScore[neighbor] = tentativeG;
                int h = std::abs(target.x - neighbor.x) + std::abs(target.y - neighbor.y);
                openSet.push({ neighbor, tentativeG, h });
            }
        }
    }

    // No path found, stay put
    return start;
}