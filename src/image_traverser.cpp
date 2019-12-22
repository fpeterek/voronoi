//
// Created by fpeterek on 22.12.19.
//

#include <image_traverser.hpp>

ImageTraverser::ImageTraverser(sf::Image & img, const std::vector<Pivot> & pivots)
        : img(img), pivots(pivots), width(img.getSize().x), height(img.getSize().y), mainPivot(pivots.back()) { }



const Pivot & ImageTraverser::findClosestPivot(const sf::Vector2i & pixel) {

    size_t closest = 0;
    uint64_t minDist = width+height;

    for (size_t i = 0; i < pivots.size(); ++i) {

        const uint64_t distance = pivots[i].distanceFrom(pixel.x, pixel.y);

        if (distance < minDist) {
            minDist = distance;
            closest = i;
        }

    }

    return pivots[closest];

}

void ImageTraverser::recalc(const uint64_t fromX, const uint64_t fromY) {

    const sf::Vector2i from(fromX, fromY);

    toVisit.emplace(from);

    while (toVisit.size()) {

        auto first = toVisit.begin();
        visit(*first);
        visited.emplace(*first);
        toVisit.erase(first);

    }

}

void ImageTraverser::visit(const sf::Vector2i & pixel) {

    const Pivot & closest = findClosestPivot(pixel);
    if (closest != mainPivot) {
        return;
    }
    getNeighbours(pixel);
    img.setPixel(pixel.x, pixel.y, mainPivot.color);

}

void ImageTraverser::getNeighbours(const sf::Vector2i & pixel) {

    std::array<sf::Vector2i, 4> neighbours = {

        sf::Vector2i(pixel.x - 1, pixel.y),
        sf::Vector2i(pixel.x + 1, pixel.y),
        sf::Vector2i(pixel.x, pixel.y - 1),
        sf::Vector2i(pixel.x, pixel.y + 1)

    };

    for (const auto & neighbour : neighbours) {
        if (inBounds(neighbour) and not isVisited(neighbour)) {
            toVisit.emplace(neighbour);
        }
    }

}

bool ImageTraverser::inBounds(const sf::Vector2i & pixel) {
    return (0 <= pixel.x and pixel.x < width and 0 <= pixel.y and pixel.y < height);
}

bool ImageTraverser::isVisited(const sf::Vector2i & pixel) {
    return visited.count(pixel);
}


