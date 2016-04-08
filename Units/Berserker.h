#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include "../Skills/MagicImmunity.h"
#include "../Weapons/Axe.h"

class Berserker : public Unit {
    public:
        Berserker(const std::string& name, int x, int y);
        ~Berserker();
};

#endif // BERSERKER_H