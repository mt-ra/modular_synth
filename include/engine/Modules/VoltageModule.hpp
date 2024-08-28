#pragma once

#include <engine/Modules/Module.hpp>

namespace engine {

class VoltageModule : public Module {
private:
    BoundedBuffer<float> *destination_;

public: // RAII member functions
    VoltageModule() = default;
    virtual ~VoltageModule() = default;

public: // interface
    void link_to(BoundedBuffer<float> *dest);
    void deliver(float v) override;
};

}
