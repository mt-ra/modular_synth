#include <engine/Modules/MidiModule.hpp>

namespace engine {

void MidiModule::link_to(BoundedBuffer<midi_msg> *dest) {
    destination_ = dest;
}

void MidiModule::deliver(midi_msg m) {
    destination_->produce(m);
}

}
