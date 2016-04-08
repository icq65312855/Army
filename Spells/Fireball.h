#ifndef FIREBALL_H
#define FIREBALL_H

#include "Spell.h"

class Fireball : public Spell {
    public:
        Fireball();
        ~Fireball();
        void action(Unit* target, Unit* caster);
};

#endif // FIREBALL_H