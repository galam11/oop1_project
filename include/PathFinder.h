#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Board;

class PathFinder
{
public:
    static sf::Vector2i findNextStep(const sf::Vector2i& start, const sf::Vector2i& target, const Board& board);

private:
    struct Vec2Comparator {
        bool operator()(const sf::Vector2i& a, const sf::Vector2i& b) const {
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        }
    };

    struct Node {
        sf::Vector2i pos;
        int g, h;
        int f() const { return g + h; }
        bool operator>(const Node& other) const { return f() > other.f(); }
    };
};