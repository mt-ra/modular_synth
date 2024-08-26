#pragma once

#define SAMPLE_RATE 44100; // sample rate of .wav
#define FRAMES_PER_BUFFER 1024;

namespace engine {

class MidiStream_PortAudio {
private: // member variables
    PaStream *stream;

public: // RAII member variables
    MidiStream_PortAudio() {
        PaError err;
        err = Pa_Initialize();
        check_err(err);
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

    ~MidiStream_PortAudio() {
        err = Pa_CloseStream(stream);
        check_err(err);
        Pa_Terminate();
        check_err(err);
    }

public: // interface
    void start() {
        err = Pa_StartStream(stream); 
        check_err(err);

        // make sure you invoke all the modules in the controller

        // do some sleeping

        err = Pa_StopStream(stream);
        check_err(err);
    }

private:
    static int callback(
        const void *inputBuffer, 
        void *outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void *data) 
    {
        auto controller = std::static_cast<MidiStream_PortAudio *>(data);
        auto out = std::static_cast<float *>(outputBuffer);
        (void) inputBuffer;
        for (unsigned long i = 0; i < framesPerBuffer; ++i) {
            float left_voltage = controller->left_output_buffer_.consume();
            float right_voltage = controller->right_output_buffer_.consume();

            *out++ = left_voltage;
            *out++ = right_voltage;
        }
        return 0;
    }
    
    void check_err(PaError err) {
        if (err != paNoError) {
            Pa_Terminate();
            std::cerr << "An error occured while using the portaudio stream" << std::endl;
            std::cerr << "Error number: " << err << std::endl;
            std::cerr << "Error message: " << Pa_GetErrorText(err) << std::endl;
            exit(EXIT_FAILURE);
        }
    }
};

}