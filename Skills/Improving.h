#ifndef IMPROVING_H
#define IMPROVING_H

#include "Skill.h"
#include "../States/StateArchery.h"
#include "../Weapons/Bow.h"

class Bow;
class StateArchery;

class Improving : public Skill {
    protected:
        Weapon* altWeapon;
        State* altState;
    public:
        Improving(Unit* owner);
        virtual ~Improving();

        virtual void action(Unit* target = 0);
        virtual State* conversionState(Unit* unit);
        virtual Weapon* conversionWeapon(Unit* unit);
};

#endif // IMPROVING_H