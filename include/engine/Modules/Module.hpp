#pragma once
#include <engine/MIDI/midi_msg.hpp>
#include <boost/circular_buffer.hpp>

// abstract class
namespace engine {

class Module {
protected: // member variables
    // parameters (modulated from outside via interface)
    vector<float> parameters;

    // how do i synchronise between these two?
    // midi input buffers
    vector<circular_buffer<midi_msg>> midi_buffer;

    // audio input buffers
    vector<circular_buffer<float>> audio_buffer;

public: // constructors

public: // operator overloads

public: // public member functions
    void set_parameter(float value) {

    }

    void add_to_parameter(float value) {

    }



private: // private member functions
    
};

}