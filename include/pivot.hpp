//
// Created by fpeterek on 22.12.19.
//

#ifndef VORONOI_PIVOT_HPP
#define VORONOI_PIVOT_HPP

#include <functional>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

struct Pivot {

    typedef std::function<int64_t(int64_t, int64_t)> DistanceFunction;

    const sf::Color color;
    const int64_t x;
    const int64_t y;

    static DistanceFunction distanceFunction;
    static void switchDistanceFunction();

    static int64_t manhattanDistance(int64_t distX, int64_t distY);
    static int64_t euclideanDistance(int64_t distX, int64_t distY);

    Pivot(sf::Color c, int64_t x, int64_t y);

    uint64_t distanceFrom(int64_t x, int64_t y) const;

    bool operator== (const Pivot & other) const;
    bool operator!= (const Pivot & other) const;

};

#endif //VORONOI_PIVOT_HPP
