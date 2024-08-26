#pragma once
#include <engine/Modules/Module.hpp>

namespace engine {

class Controller {
protected: // member variables
std::vector<Module> modules_;

public: // interface functions

    // use dynamic dispatch
    virtual void link(Module &src, Module &dest, size_t port);

};

}