#include "StateVampire.h"

StateVampire::StateVampire() :
    State("Vampire", 150, true, 2) {
        this->immutable = true;
    }

StateVampire::~StateVampire() {}