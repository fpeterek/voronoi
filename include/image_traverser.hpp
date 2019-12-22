//
// Created by fpeterek on 22.12.19.
//

#ifndef VORONOI_IMAGE_TRAVERSER_HPP
#define VORONOI_IMAGE_TRAVERSER_HPP

#include <vector>
#include <unordered_set>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "pivot.hpp"

struct Hash {

    template <typename type>
    size_t operator() (const sf::Vector2<type> & vector) const {

        size_t h1 = std::hash<type>()(vector.x);
        size_t h2 = std::hash<type>()(vector.y);

        return (h1 << 1) ^ h2;

    }

};

class ImageTraverser {

    std::unordered_set<sf::Vector2i, Hash> visited;
    std::unordered_set<sf::Vector2i, Hash> toVisit;

    const Pivot & mainPivot;

    sf::Image & img;
    const std::vector<Pivot> & pivots;

    const uint64_t width;
    const uint64_t height;

    bool inBounds(const sf::Vector2i & pixel);

    void getNeighbours(const sf::Vector2i & pixel);
    const Pivot & findClosestPivot(const sf::Vector2i & pixel);
    bool isVisited(const sf::Vector2i & pixel);
    void visit(const sf::Vector2i & pixel);

public:

    ImageTraverser(sf::Image & img, const std::vector<Pivot> & pivots);

    void recalc(uint64_t fromX, uint64_t fromY);

};

#endif //VORONOI_IMAGE_TRAVERSER_HPP
