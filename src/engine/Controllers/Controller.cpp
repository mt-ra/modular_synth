
#include <memory>
#include <engine/Controllers/Controller.hpp>

namespace engine {

void Controller::add_module(std::shared_ptr<Module> mod) {
    modules_.push_back(mod);
}

void Controller::link(
    std::shared_ptr<Module> src, 
    std::shared_ptr<Module> dest, 
    size_t port
) {
    src->link_to(dest, port);
}

void Controller::set_bpm(float new_bpm) {
    bpm_ = new_bpm;
    for (auto m : modules_) {
        m.set_bpm(bpm_);
    }
}

void Controller::set_parameter(
    size_t module_number, 
    size_t param_number, 
    float val
) {
    modules_.at(module_number)->set_parameter(param_number, val);
}

}