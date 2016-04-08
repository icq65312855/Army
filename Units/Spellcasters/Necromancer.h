#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "SpellCaster.h"
#include "../../Skills/Observer.h"

class Necromancer : public Spellcaster {
    public:
        Necromancer(const std::string& name, int x, int y);
        virtual ~Necromancer();

        virtual void conversion(Unit* owner);
};

#endif // NECROMANCER_H