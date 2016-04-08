#ifndef STATEARCHERY_H
#define STATEARCHERY_H

#include "State.h"
#include "../Units/Unit.h"
#include "../Skills/Transform.h"
#include "../Weapons/Claws.h"

class StateArchery : public State {
    public:
        StateArchery();
        virtual ~StateArchery();
};

#endif // STATEARCHERY_H