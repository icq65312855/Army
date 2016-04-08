#ifndef STATEVAMPIRE_H
#define STATEVAMPIRE_H

#include "State.h"
#include "../Units/Unit.h"
#include "../Skills/Vampiric.h"
#include "../Weapons/Fangs.h"

class StateVampire : public State {
    public:
        StateVampire();
        virtual ~StateVampire();
};

#endif // STATEVAMPIRE_H