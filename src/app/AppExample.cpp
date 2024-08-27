#include <iostream>
#include <app/AppExample.hpp>
//#include <engine/Controllers/MidiStream_PortAudio.hpp>
//#include <engine/Modules/Saw.hpp>

// RAII member functions
AppExample::AppExample() {

}

// public member function
void AppExample::run() {
    //engine::MidiStream_PortAudio con{}; // put a MIDI stream object in the constructor
    std::cout << "Hello world!" << std::endl;
}
