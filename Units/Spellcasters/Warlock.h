#ifndef WARLOCK_H
#define WARLOCK_H

#include "SpellCaster.h"
#include "../../Skills/Summon.h"

class Warlock : public Spellcaster {
    public:
        Warlock(const std::string& name, int x, int y);
        virtual ~Warlock();

        virtual void conversion(Unit* owner);
};

#endif // WARLOCK_H
