#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Board;

class PathFinder
{
public:
    struct Node {
        sf::Vector2i pos;
        int g, h;
        int f() const { return g + h; }
        bool operator>(const Node& other) const { return f() > other.f(); }
    };

    static sf::Vector2i findNextStep(const sf::Vector2i& start, const sf::Vector2i& target, const Board& board);

private:
    static std::vector<sf::Vector2i> getNeighbors(const sf::Vector2i& curr, const Board& board);
    static bool isWalkable(int r, int c, const Board& board);
};