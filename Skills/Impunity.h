#ifndef IMPUNITY_H
#define IMPUNITY_H

#include "Skill.h"

class Impunity : public Skill {
    public:
        Impunity(Unit* owner);
        virtual ~Impunity();

        virtual void modAttack(int damage, Unit* target);
};

#endif // IMPUNITY_H