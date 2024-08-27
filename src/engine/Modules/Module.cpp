#include <memory>
#include <engine/Modules/Module.hpp>
#include <engine/BoundedBuffer.hpp>

namespace engine {

void Module::set_bpm(float bpm) {
    bpm_ = bpm;
}

void Module::set_sample_rate_(unsigned int sr) {
    voltage_sample_rate_ = sr;
}

void Module::set_parameter(size_t param_number, float value) {
    parameters_.at(param_number) = value;
}

void Module::increase_parameter(size_t param_number, float value) {
    parameters_.at(param_number) += value;
}

void Module::deliver(float v) {
    // do nothing
}

void Module::deliver(midi_msg m) {
    // do nothing
}

}
