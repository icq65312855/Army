#ifndef ICEBOLT_H
#define ICEBOLT_H

#include "Spell.h"

class IceBolt : public Spell {
    public:
        IceBolt();
        ~IceBolt();
        void action(Unit* target, Unit* caster);
};

#endif // ICEBOLT_H