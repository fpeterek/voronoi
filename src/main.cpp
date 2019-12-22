#include "graph_window.hpp"

void parseArgs(int argc, const char * argv[]) {

    if (argc <= 1) {
        return;
    }

    std::string arg = argv[1];

    if (arg == "-m" or arg == "--manhattan") {
        Pivot::switchDistanceFunction();
    }

}

int main(int argc, const char * argv[]) {

    parseArgs(argc, argv);

    GraphWindow window;

    while (window.isOpen()) {
        window.handleEvents();
    }

}
