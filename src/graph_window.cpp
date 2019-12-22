//
// Created by fpeterek on 22.12.19.
//

#include "graph_window.hpp"
#include "image_traverser.hpp"

const std::vector<sf::Color> GraphWindow::colorSequence = {
    sf::Color(255, 187, 0),
    sf::Color(0, 255, 157),
    sf::Color(211, 61, 245),
    sf::Color(245, 61, 61),
    sf::Color(255, 139, 38),
    sf::Color(194, 255, 38),
    sf::Color(38, 230, 255),
    sf::Color(255, 38, 147),
    sf::Color(38, 201, 255),
    sf::Color(255, 38, 157),
    sf::Color(38, 255, 186),
    sf::Color(194, 255, 38),
    sf::Color(255, 92, 38),
    sf::Color(255, 237, 38)
};

GraphWindow::GraphWindow() : sf::RenderWindow(sf::VideoMode(width, height), "Voronoi Diagram") {

    img.create(width, height, sf::Color::White);
    txt.loadFromImage(img);
    sprite.setTexture(txt);
    redraw();

}

void GraphWindow::handleEvents() {

    sf::Event ev;
    while (pollEvent(ev)) {

        if (ev.type == sf::Event::Closed) {
            return close();
        }

        if (ev.type == sf::Event::KeyPressed and ev.key.code == sf::Keyboard::Escape) {
            return close();
        }

        if (ev.type == sf::Event::MouseButtonPressed and ev.mouseButton.button == sf::Mouse::Left) {
            createPivot(ev.mouseButton.x, ev.mouseButton.y);
        }

        if (ev.type == sf::Event::KeyPressed and ev.key.code == sf::Keyboard::Space) {
            showPivots = not showPivots;
            redraw();
        }

    }

}

void GraphWindow::createPivotIndicator() {

    sf::CircleShape circle(5);
    circle.setFillColor(pivots.back().color);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(2);
    circle.setOrigin(3, 3);
    circle.setPosition(pivots.back().x, pivots.back().y);
    pivotIndicators.emplace_back(circle);

}

void GraphWindow::createPivot(const uint64_t x, const uint64_t y) {

    pivots.emplace_back(Pivot(colorSequence[color++], x, y));
    createPivotIndicator();

    if (pivots.size() == 1) {
        firstPivot();
    } else {
        updateImage(x, y);
    }

    txt.loadFromImage(img);
    color %= colorSequence.size();

    redraw();

}


void GraphWindow::firstPivot() {

    img.create(width, height, pivots.front().color);
    txt.loadFromImage(img);

}

void GraphWindow::redraw() {

    clear();
    draw(sprite);
    drawPivots();
    display();

}

void GraphWindow::updateImage(uint64_t x, uint64_t y) {

    ImageTraverser traverser(img, pivots);
    traverser.recalc(x, y);

}

void GraphWindow::drawPivots() {

    if (not showPivots) {
        return;
    }

    for (const auto & indicator : pivotIndicators) {
        draw(indicator);
    }

}

