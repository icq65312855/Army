#ifndef HEALING_H
#define HEALING_H

#include "Skill.h"

class Healing : public Skill {
    public:
        Healing(Unit* owner);
        virtual ~Healing();
        
        virtual int modActionPoint(int actionPoint, Unit* target, Spell* spell);
};

#endif // HEALING_H