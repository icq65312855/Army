#include "Priest.h"

Priest::Priest(const std::string& name, int x, int y)
    : Spellcaster(name, "Priest", 80, 100, new Staff(), new Holy(this), gameboard->getLocation(x, y)) {
        this->spellbook->addSpell(spell_IceBolt, new IceBolt());
        this->spellbook->addSpell(spell_Heal, new Heal());
        this->spellbook->selectSpell(spell_IceBolt);
}

Priest::~Priest() {}