#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"
#include "../../Skills/Healing.h"

class Healer : public Spellcaster {
    public:
        Healer(const std::string& name, int x, int y);
        virtual ~Healer();
};

#endif // HEALER_H
