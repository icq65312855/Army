#include "Healer.h"

Healer::Healer(const std::string& name, int x, int y)
    : Spellcaster(name, "Healer", 80, 100, new Staff(), new Healing(this), gameboard->getLocation(x, y)) {
        this->spellbook->addSpell(spell_Fireball, new Fireball());
        this->spellbook->addSpell(spell_Heal, new Heal());
        this->spellbook->selectSpell(spell_Heal);
}

Healer::~Healer() {}