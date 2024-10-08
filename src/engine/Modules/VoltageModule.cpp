#include <engine/Modules/VoltageModule.hpp>

namespace engine {

void VoltageModule::link_to(BoundedBuffer<float> *dest) {
    destination_ = dest;
}

void VoltageModule::deliver(float v) {
    destination_->produce(v);
}

}
