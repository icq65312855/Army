#ifndef STATEHUMAN_H
#define STATEHUMAN_H

#include "State.h"
#include "../Units/Unit.h"
#include "../Skills/Transform.h"
#include "../Weapons/Claws.h"

class StateHuman : public State {
    public:
        StateHuman();
        virtual ~StateHuman();
};

#endif // STATEHUMAN_H