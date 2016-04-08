#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include "../../Skills/Holy.h"

class Priest : public Spellcaster {
    public:
        Priest(const std::string& name, int x, int y);
        virtual ~Priest();
};

#endif // PRIEST_H
