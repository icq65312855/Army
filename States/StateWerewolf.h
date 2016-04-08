#ifndef STATEWEREWOLF_H
#define STATEWEREWOLF_H

#include "State.h"
#include "../Units/Unit.h"
#include "../Skills/Transform.h"
#include "../Weapons/Claws.h"

class StateWerewolf : public State {
    public:
        StateWerewolf();
        virtual ~StateWerewolf();

        virtual int takeMagicDamage(int dmg);
};

#endif // STATEWEREWOLF_H