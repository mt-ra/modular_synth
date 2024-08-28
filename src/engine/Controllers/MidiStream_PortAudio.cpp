#include <iostream>
#include <thread>
#include <engine/Controllers/MidiStream_PortAudio.hpp>

int fuck = 0;

namespace engine {

MidiStream_PortAudio::MidiStream_PortAudio() : Controller() {
    PaError err;
    err = Pa_Initialize();
    check_err(err);
    std::cerr << "Device count = " << Pa_GetDeviceCount() << std::endl;
    std::cerr << "Opening Default Stream: " << std::endl;
    err = Pa_OpenDefaultStream(
        &stream,
        0,
        2,
        paFloat32,
        SAMPLE_RATE,
        FRAMES_PER_BUFFER,
        MidiStream_PortAudio::callback,
        this
    );
    check_err(err);
}

MidiStream_PortAudio::~MidiStream_PortAudio() {
    PaError err = Pa_CloseStream(stream);
    check_err(err);
    Pa_Terminate();
    check_err(err);
}

void MidiStream_PortAudio::start() {
    std::cerr << "Starting stream..." << std::endl;
    PaError err = Pa_StartStream(stream); 
    check_err(err);

    // TODO:
    // make sure you invoke all the modules in the controller

    std::cerr << "Starting modules..." << std::endl;
    start_modules();

    std::cerr << "sleeping a bit..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(20));
    
    std::cerr << "Sleep finished!" << std::endl;

    // do some sleeping

    err = Pa_StopStream(stream);
    check_err(err);
}

int MidiStream_PortAudio::callback(
    const void *inputBuffer, 
    void *outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void *data) 
{
    auto controller = static_cast<MidiStream_PortAudio *>(data);
    auto out = static_cast<float *>(outputBuffer);
    (void) inputBuffer;
    for (unsigned long i = 0; i < framesPerBuffer; ++i) {
        float left_voltage = controller->left_output_buffer_.consume();
        float right_voltage = controller->right_output_buffer_.consume();
        *out++ = left_voltage;
        *out++ = right_voltage;
    }
    return 0;
}

void MidiStream_PortAudio::check_err(PaError err) {
    if (err != paNoError) {
        Pa_Terminate();
        std::cerr << "An error occured while using the portaudio stream" << std::endl;
        std::cerr << "Error number: " << err << std::endl;
        std::cerr << "Error message: " << Pa_GetErrorText(err) << std::endl;
        exit(EXIT_FAILURE);
    }
}

}
