#ifndef OBSERVER_H
#define OBSERVER_H

#include "Skill.h"

class Observer : public Skill {
    public:
        Observer(Unit* owner);
        ~Observer();

        virtual void modAttack(int damage, Unit* target);
        virtual void modCounterAttack(int damage, Unit* target);
        virtual int modActionPoint(int actionPoint, Unit* target, Spell* spell);
};

#endif // OBSERVER_H