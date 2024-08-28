#include <iostream>
#include <engine/Modules/TestSquare.hpp>

namespace engine {

void TestSquare::start() {
    std::cerr << "TestSquare started" << std::endl;
    while (on_) {
        // it's not even a square !!
        for (float i = -1; i < 1; i += 0.05) {
            deliver(i);
        }
    }
}
}
