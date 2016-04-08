#include "StateHuman.h"

StateHuman::StateHuman() :
    State("Human", 120, false, 1) {
        this->immutable = true;
    }

StateHuman::~StateHuman() {}
