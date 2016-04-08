#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../Exceptions.h"
#include "../Skills/Skill.h"
#include "../Weapons/Weapon.h"

class Skill;
class Weapon;

class State {
    protected:
        int hitPointsLimit;
        int hitPoints;
        std::string className;
        bool undead;
        int maxDistance;
        bool immutable;
    public:
        State(const std::string& className, int hitPointsLimit, bool undead = false, int maxDistance = 1);
        virtual ~State();

        void ensureIsAlive();
        int getHitPointsLimit();
        int getHitPoints();
        const std::string& getClassName();
        virtual bool getUndead();
        virtual int getMaxDistance();
        virtual bool getImmutable();

        virtual int takeDamage(int dmg);
        virtual int takeMagicDamage(int dmg);
        virtual int addHitPoints(int hp);
};

#endif // STATE_H