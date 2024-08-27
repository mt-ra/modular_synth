#pragma once

#include <engine/Controllers/Controller.hpp>
#include <portaudio.h>

#define SAMPLE_RATE 44100 // sample rate of .wav
#define FRAMES_PER_BUFFER 1024

namespace engine {

class MidiStream_PortAudio : public Controller {
private: // member variables
    PaStream *stream;

public: // RAII member variables
    MidiStream_PortAudio();
    ~MidiStream_PortAudio();

public: // interface
    void start() override;

private:
    static void check_err(PaError err);
    static int callback(
        const void *inputBuffer, 
        void *outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void *data
    );
    
};

}