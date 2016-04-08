#ifndef HOLY_H
#define HOLY_H

#include "Skill.h"

class Holy : public Skill {
    public:
        Holy(Unit* owner);
        virtual ~Holy();

        virtual int modActionPoint(int actionPoint, Unit* target, Spell* spell);
};

#endif // HOLY_H