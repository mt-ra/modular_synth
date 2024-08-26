#pragma once
#include <boost/circular_buffer.hpp>

#include <engine/MIDI/midi_msg.hpp>
#include <engine/BoundedBuffer.hpp>

namespace engine {

class Module {
protected: // member variables
    unsigned int voltage_sample_rate_;
    vector<float> parameters_;

    // each bounded buffer represents a port
    BoundedBuffer<midi_msg> midi_buffer_;
    BoundedBuffer<float> voltage_buffer_;

public: // constructors
    Module();

public: // operator overloads

public: // public member functions
    void set_parameter(float value);
    void add_to_parameter(float value);
    virtual link_to(Module &dest) = 0;

private: // private member functions
    
};

}