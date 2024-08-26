#pragma once

#include <memory>
#include <boost/circular_buffer.hpp>
#include <engine/MIDI/midi_msg.hpp>
#include <engine/BoundedBuffer.hpp>

namespace engine {

class Module {
protected: // member variables
    std::atomic<bool> on_;

    // global information provided by controller
    float bpm_;
    unsigned int voltage_sample_rate_;

    // parameters
    vector<float> parameters_;

    // input buffers
    BoundedBuffer<midi_msg> midi_buffer_;
    BoundedBuffer<float> voltage_buffer_;

    // destination information
    std::shared_ptr<Module> destination_;
    size_t dest_port_number_;

public: // RAII member functions
    Module();
    virtual ~Module() = 0;
    Module(Module const &other) = delete;
    Module &operator=(Module const &other) = delete;

public: // public member functions
    void set_bpm(float bpm);
    void set_sample_rate_(unsigned int sr);

    void set_parameter(size_t param_number, float value);
    void increase_parameter(size_t param_number, float value);
    void link_to(std::shared_ptr<Module> dest, size_t port_number) = 0;

    // where the actual module logic is implemented
    virtual void generate();

private: // private member functions
    virtual void deliver();
};

}