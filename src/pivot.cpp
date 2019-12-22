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

    return distanceFunction(distX, distY);

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

Pivot::DistanceFunction Pivot::distanceFunction = Pivot::euclideanDistance;

int64_t Pivot::manhattanDistance(int64_t distX, int64_t distY) {
    return std::abs(distX) + std::abs(distY);
}

int64_t Pivot::euclideanDistance(int64_t distX, int64_t distY) {
    return std::sqrt(distX*distX + distY*distY);
}

void Pivot::switchDistanceFunction() {
    distanceFunction = Pivot::manhattanDistance;
}
