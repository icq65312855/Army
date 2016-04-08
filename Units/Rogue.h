#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include "../Skills/Impunity.h"
#include "../Weapons/Dagger.h"

class Rogue : public Unit {
    public:
        Rogue(const std::string& name, int x, int y);
        ~Rogue();
};

#endif // ROGUE_H