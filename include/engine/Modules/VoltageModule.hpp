#include <engine/Modules/Module.hpp>

namespace engine {

class VoltageModule : public Module {
private:
    BoundedBuffer<float> *destination_;

public: // RAII member functions
    VoltageModule() = default;
    virtual ~VoltageModule() = 0;

public: // interface
    void link_to(BoundedBuffer<float> *dest);
    void deliver(float v) override;
};

}