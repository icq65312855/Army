#ifndef VAMPIRIC_H
#define VAMPIRIC_H

#include "Skill.h"
#include "../States/StateVampire.h"
#include "../Weapons/Claws.h"

class Vampiric : public Skill {
    public:
        Vampiric(Unit* owner);
        virtual ~Vampiric();

        virtual void modAttack(int damage, Unit* target);
        virtual void modCounterAttack(int damage, Unit* target);
        virtual State* conversionState(Unit* unit);
        virtual Skill* conversionSkill(Unit* unit);
        virtual Weapon* conversionWeapon(Unit* unit);
};

#endif // VAMPIRIC_H