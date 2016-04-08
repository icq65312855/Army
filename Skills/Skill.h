#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include "../Units/Unit.h"
#include "../Spells/Spell.h"
#include "../States/State.h"
#include "../Weapons/Weapon.h"

class Unit;
class State;
class Spell;
class Demon;

class Skill {
    protected:
        Unit* owner;
    public:
        Skill(Unit* owner);
        virtual ~Skill();

        virtual void modAttack(int damage, Unit* target);
        virtual void modCounterAttack(int damage, Unit* target);
        virtual int modActionPoint(int actionPoint, Unit* target, Spell* spell);
        virtual int modTakeMagicDamage(int damage);
        virtual void action(Unit* target = 0);
        virtual State* conversionState(Unit* unit);
        virtual Skill* conversionSkill(Unit* unit);
        virtual Weapon* conversionWeapon(Unit* unit);
        virtual Demon* demon();
        virtual void freeSlave();
};

#endif // SKILL_H