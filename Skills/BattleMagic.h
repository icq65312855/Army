#ifndef BATTLEMAGIC_H
#define BATTLEMAGIC_H

#include "Skill.h"

class BattleMagic : public Skill {
    public:
        BattleMagic(Unit* owner);
        virtual ~BattleMagic();

        virtual int modActionPoint(int actionPoint, Unit* target, Spell* spell);
};

#endif // BATTLEMAGIC_H