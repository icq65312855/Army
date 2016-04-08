#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../Units/Unit.h"

class Unit;

class Spell {
    protected:
        int cost;
        int actionPoint;
        int maxDistance;
        std::string name;
    public:
        Spell(int cost, int actionPoint, const std::string& name, int maxDistance);
        virtual ~Spell();

        int getCost();
        int getActionPoint();
        virtual bool isHeal();
        const std::string& getSpellName();
        const int getMaxDistance();
        bool ensureIsDistance(Unit* target, Unit* caster);

        virtual void action(Unit* target, Unit* caster) = 0;
};

#endif // SPELL_H