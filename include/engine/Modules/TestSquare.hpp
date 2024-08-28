#pragma once

#include <engine/Modules/VoltageModule.hpp>

namespace engine {

class TestSquare : public VoltageModule {
public:
    TestSquare() {

    }
public:
    void start() override;
};

}
