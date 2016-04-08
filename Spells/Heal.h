#ifndef HEAL_H
#define HEAL_H

#include "Spell.h"

class Heal : public Spell {
    public:
        Heal();
        ~Heal();
        bool isHeal();
        void action(Unit* target, Unit* caster);
};

#endif // HEAL_H