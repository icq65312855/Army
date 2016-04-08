#ifndef SUMMON_H
#define SUMMON_H

#include "Skill.h"
#include "../Units/Demon.h"

class Demon;

class Summon : public Skill {
    protected:
        Demon* slave;
    public:
        Summon(Unit* owner);
        virtual ~Summon();

        virtual void action(Unit* target = 0);
        virtual Demon* demon();
        virtual void freeSlave();
};

#endif // SUMMON_H