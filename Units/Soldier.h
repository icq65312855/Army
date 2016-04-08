#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "../Weapons/Sword.h"
#include "../Skills/Improving.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name, int x, int y);
        virtual ~Soldier();
};

#endif // SOLDIER_H