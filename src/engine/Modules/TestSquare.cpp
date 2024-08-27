#include <engine/Modules/TestSquare.hpp>

namespace engine {

void TestSquare::start() {
    while (on_) {
        // it's not even a square !!
        for (float i = -1; i < 1; i += 0.001) {
            deliver(i);
        }
    }
}
}
