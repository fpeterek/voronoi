#include <image_traverser.hpp>
#include "graph_window.hpp"

void handleArg(const std::string & arg) {

    if (arg == "-m" or arg == "--manhattan") {
        Pivot::switchDistanceFunction();
    }

    if (arg == "-b" or arg == "--borders") {
        ImageTraverser::enableBorderRendering();
    }

}

void parseArgs(const int argc, const char * argv[]) {

    for (int i = 1; i < argc; ++i) {

        handleArg(argv[i]);

    }

}

int main(int argc, const char * argv[]) {

    parseArgs(argc, argv);

    GraphWindow window;

    while (window.isOpen()) {
        window.handleEvents();
    }

}
