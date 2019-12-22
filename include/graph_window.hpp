//
// Created by fpeterek on 22.12.19.
//

#ifndef VORONOI_GRAPH_WINDOW_HPP
#define VORONOI_GRAPH_WINDOW_HPP

#include <SFML/Graphics.hpp>

#include "pivot.hpp"

class GraphWindow : public sf::RenderWindow {

    static const uint64_t width = 800;
    static const uint64_t height = 500;

    static const std::vector<sf::Color> colorSequence;

    size_t color = 0;
    bool showPivots = true;
    std::vector<Pivot> pivots;
    std::vector<sf::CircleShape> pivotIndicators;
    sf::Image img;
    sf::Texture txt;
    sf::Sprite sprite;

    void createPivotIndicator();
    void createPivot(uint64_t x, uint64_t y);
    void firstPivot();
    void updateImage(uint64_t x, uint64_t y);
    void drawPivots();
    void redraw();

public:

    GraphWindow();

    void handleEvents();

};

#endif //VORONOI_GRAPH_WINDOW_HPP
