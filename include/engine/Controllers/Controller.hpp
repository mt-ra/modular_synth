#pragma once
#include <memory>
#include <thread>
#include <engine/Modules/Module.hpp>
#include <engine/Modules/VoltageModule.hpp>
#include <engine/Modules/MidiModule.hpp>

namespace engine {

class Controller {
protected: // member variables
float bpm_;
float sample_rate_;

std::vector<std::shared_ptr<Module>> modules_;
std::vector<std::thread> module_threads_;

public:
BoundedBuffer<float> left_output_buffer_;
BoundedBuffer<float> right_output_buffer_;

public: // RAII member functions
    Controller();
    virtual ~Controller() = 0;
    Controller(Controller const &other) = delete;
    Controller &operator=(Controller const &other) = delete;

public: // interface functions
    // during setup
    void add_module(std::shared_ptr<Module> mod);
    void link(std::shared_ptr<VoltageModule> src, std::shared_ptr<Module> dest, size_t port);
    void link(std::shared_ptr<MidiModule> src, std::shared_ptr<Module> dest, size_t port);
    void link_left_output(std::shared_ptr<VoltageModule> src);
    void link_right_output(std::shared_ptr<VoltageModule> src);

    virtual void start() = 0;

public: // functions for interacting with modules during runtime
    void set_bpm(float new_bpm);
    void set_parameter(size_t module_number, size_t param_number, float val);

protected:
    void start_modules();
};

}
