#ifndef MAGICIMMUNITY_H
#define MAGICIMMUNITY_H

#include "Skill.h"

class MagicImmunity : public Skill {
    public:
        MagicImmunity(Unit* owner);
        virtual ~MagicImmunity();

        virtual int modTakeMagicDamage(int damage);
};

#endif // MAGICIMMUNITY_H