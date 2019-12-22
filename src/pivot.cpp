//
// Created by fpeterek on 22.12.19.
//

#include "pivot.hpp"

#include <cmath>

#include <SFML/Graphics.hpp>

Pivot::Pivot(sf::Color c, int64_t x, int64_t y) : color(c), x(x), y(y) { }

uint64_t Pivot::distanceFrom(const int64_t otherX, const int64_t otherY) const {

    const int64_t distX = otherX - x;
    const int64_t distY = otherY - y;

    return std::sqrt(distX*distX + distY*distY);

}

bool Pivot::operator==(const Pivot & other) const {
    if (this == &other) {
        return true;
    }
    return x == other.x and y == other.y and color == other.color;
}

bool Pivot::operator!=(const Pivot & other) const {
    return not (operator==(other));
}
