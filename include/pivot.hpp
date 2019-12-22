//
// Created by fpeterek on 22.12.19.
//

#ifndef VORONOI_PIVOT_HPP
#define VORONOI_PIVOT_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

struct Pivot {

    const sf::Color color;
    const int64_t x;
    const int64_t y;

    Pivot(sf::Color c, int64_t x, int64_t y);

    uint64_t distanceFrom(int64_t x, int64_t y) const;

    bool operator== (const Pivot & other) const;
    bool operator!= (const Pivot & other) const;

};

#endif //VORONOI_PIVOT_HPP
