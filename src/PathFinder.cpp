#include "PathFinder.h"
#include "Board.h"
#include <queue>
#include <cmath>

sf::Vector2i PathFinder::findNextStep(const sf::Vector2i& start, const sf::Vector2i& target, const Board& board)
{
    auto gridSize = board.getGridSize();
    if (gridSize.x == 0 || gridSize.y == 0 || start == target) return start;

    auto gridToIndex = [&](const sf::Vector2i& p) { return p.y * gridSize.x + p.x; };

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;
    std::vector<int> gScore(gridSize.x * gridSize.y, 1000000);
    std::vector<int> parent(gridSize.x * gridSize.y, -1);

    gScore[gridToIndex(start)] = 0;
    openSet.push({ start, 0, std::abs(target.x - start.x) + std::abs(target.y - start.y) });

    while (!openSet.empty())
    {
        Node curr = openSet.top();
        openSet.pop();

        if (curr.pos == target)
        {
            int currIdx = gridToIndex(curr.pos);
            while (parent[currIdx] != -1 && parent[currIdx] != gridToIndex(start))
                currIdx = parent[currIdx];

            return sf::Vector2i(currIdx % gridSize.x, currIdx / gridSize.x);
        }

        for (auto& neighbor : getNeighbors(curr.pos, board))
        {
            int nIdx = gridToIndex(neighbor);
            int tentativeG = gScore[gridToIndex(curr.pos)] + 1;

            if (tentativeG < gScore[nIdx])
            {
                parent[nIdx] = gridToIndex(curr.pos);
                gScore[nIdx] = tentativeG;
                openSet.push({ neighbor, tentativeG, std::abs(target.x - neighbor.x) + std::abs(target.y - neighbor.y) });
            }
        }
    }
    return start;
}

std::vector<sf::Vector2i> PathFinder::getNeighbors(const sf::Vector2i& curr, const Board& board)
{
    std::vector<sf::Vector2i> neighbors;
    char tile = board.getTile(curr.y, curr.x);
    char tileBelow = board.getTile(curr.y + 1, curr.x);

    bool onFloor = (tileBelow == '#' || tileBelow == '^' || tileBelow == 'H');
    bool onRail = (tile == '-');
    bool onLadder = (tile == 'H');

    // Horizontal: only if supported by floor/rail/ladder
    if ((onFloor || onRail || onLadder)) {
        if (isWalkable(curr.y, curr.x - 1, board)) neighbors.push_back({ curr.x - 1, curr.y });
        if (isWalkable(curr.y, curr.x + 1, board)) neighbors.push_back({ curr.x + 1, curr.y });
    }

    // Vertical: Up only if on ladder, Down if on ladder or empty space (falling)
    if (onLadder && isWalkable(curr.y - 1, curr.x, board))
        neighbors.push_back({ curr.x, curr.y - 1 });

    if ((onLadder || tileBelow == ' ' || tileBelow == '-' || tileBelow == 'H' || tileBelow == '*')
        && isWalkable(curr.y + 1, curr.x, board))
        neighbors.push_back({ curr.x, curr.y + 1 });

    return neighbors;
}

bool PathFinder::isWalkable(int r, int c, const Board& board)
{
    auto size = board.getGridSize();
    if (r < 0 || r >= (int)size.y || c < 0 || c >= (int)size.x) return false;
    char t = board.getTile(r, c);
    return (t != '#' && t != '^');
}