#include <iostream>
#include <memory>
#include <engine/Controllers/Controller.hpp>

namespace engine {

Controller::Controller() : left_output_buffer_(), right_output_buffer_() {
    std::cerr << "Controller constructor" << std::endl;
}

void Controller::add_module(std::shared_ptr<Module> mod) {
    modules_.push_back(mod);
}

void Controller::link(
    std::shared_ptr<VoltageModule> src, 
    std::shared_ptr<Module> dest, 
    size_t port
) {
    src->link_to(&(dest->voltage_buffers_.at(port)));
}

void Controller::link(
    std::shared_ptr<MidiModule> src, 
    std::shared_ptr<Module> dest, 
    size_t port
) {
    src->link_to(&(dest->midi_buffers_.at(port)));
}

void Controller::link_left_output(std::shared_ptr<VoltageModule> src) {
    src->link_to(&left_output_buffer_);
}

void Controller::link_right_output(std::shared_ptr<VoltageModule> src) {
    src->link_to(&right_output_buffer_);
}

void Controller::set_bpm(float new_bpm) {
    bpm_ = new_bpm;
    for (auto m : modules_) {
        m->set_bpm(bpm_);
    }
}

void Controller::set_sample_rate(unsigned int new_sample_rate) {
    sample_rate_ = new_sample_rate;
    for (auto m : modules_) {
        m->set_sample_rate(sample_rate_);
    }
}

void Controller::set_parameter(
    size_t module_number, 
    size_t param_number, 
    float val
) {
    modules_.at(module_number)->set_parameter(param_number, val);
}

void Controller::start_modules() {
    // controller is responsible for multithreading
    for (auto m : modules_) {
        module_threads_.push_back(std::thread([m](){
            m->start();
        }));
    }
}

}
