#include <iostream>
#include <memory>
#include <app/AppExample.hpp>
#include <engine/Controllers/MidiStream_PortAudio.hpp>
#include <engine/Modules/TestSquare.hpp>

// RAII member functions
AppExample::AppExample() {

}

// public member function
void AppExample::run() {
    engine::MidiStream_PortAudio con{}; // put a MIDI stream object in the constructor
    auto square1 = std::make_shared<engine::TestSquare>();
    auto square2 = std::make_shared<engine::TestSquare>();
    con.add_module(square1);
    con.add_module(square2);
    con.link_left_output(square1);
    con.link_right_output(square2);

    std::cout << "Hello world!" << std::endl;
    con.start();
}
