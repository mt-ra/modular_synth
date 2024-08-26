#include <engine/Modules/Module.hpp>
#include <engine/MIDI/midi_msg.hpp>

namespace engine {

class MidiModule : public Module {
private:
    BoundedBuffer<midi_msg> *destination_;

public: // RAII member functions
    MidiModule() = default;
    virtual ~MidiModule() = 0;

public: // interface
    void link_to(BoundedBuffer<midi_msg> *dest);
    void deliver(midi_msg m) override;
};

}
