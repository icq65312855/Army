#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"
#include "../../Skills/BattleMagic.h"

class Wizard : public Spellcaster {
    public:
        Wizard(const std::string& name, int x, int y);
        virtual ~Wizard();
};

#endif // WIZARD_H
