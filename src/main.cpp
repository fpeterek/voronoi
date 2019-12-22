#include "graph_window.hpp"


int main() {

    GraphWindow window;

    while (window.isOpen()) {
        window.handleEvents();
    }

}
