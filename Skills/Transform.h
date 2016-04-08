#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Skill.h"
#include "../States/StateWerewolf.h"
#include "../States/StateHuman.h"
#include "../Weapons/Sword.h"

class Transform : public Skill {
    protected:
        State* altState;
        Weapon* altWeapon;
    public:
        Transform(Unit* owner, State* altState, Weapon* altWeapon);
        virtual ~Transform();

        virtual void action(Unit* target = 0);
        virtual void modAttack(int damage, Unit* target);
        virtual void modCounterAttack(int damage, Unit* target);
        virtual State* conversionState(Unit* unit);
        virtual Skill* conversionSkill(Unit* unit);
        virtual Weapon* conversionWeapon(Unit* unit);
};

#endif // TRANSFORM_H