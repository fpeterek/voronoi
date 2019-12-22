cmake_minimum_required(VERSION 3.15)
project(voronoi)

set(CMAKE_CXX_STANDARD 14)

include_directories(include /usr/include)

link_libraries(-lsfml-window -lsfml-graphics -lsfml-system)

add_executable(voronoi src/main.cpp include/graph_window.hpp src/graph_window.cpp include/pivot.hpp src/pivot.cpp include/image_traverser.hpp src/image_traverser.cpp)
