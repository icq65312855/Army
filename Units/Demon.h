#ifndef DEMON_H
#define DEMON_H

#include "Unit.h"
#include "../Weapons/Spike.h"

class Demon : public Unit {
    protected:
        Unit* master;
    public:
        Demon(Unit* master, int x, int y);
        virtual ~Demon();

        virtual int takeDamage(int dmg);
};

#endif // DEMON_H