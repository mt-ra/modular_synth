#pragma once

#include <memory>
#include <atomic>
#include <vector>
#include <engine/MIDI/midi_msg.hpp>
#include <engine/BoundedBuffer.hpp>

namespace engine {

class Module {
protected: // member variables
    std::atomic<bool> on_ = true;

    // global information provided by controller
    float bpm_;
    unsigned int voltage_sample_rate_;

    // parameters
    std::vector<float> parameters_;

public:
    // input buffers
    std::vector<BoundedBuffer<midi_msg>> midi_buffers_;
    std::vector<BoundedBuffer<float>> voltage_buffers_;

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

    // where the actual module logic is implemented
    virtual void start() = 0;

private: // private member functions
    virtual void deliver(float v);
    virtual void deliver(midi_msg m);
};

}