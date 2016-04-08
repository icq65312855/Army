#include "Warlock.h"

Warlock::Warlock(const std::string& name, int x, int y)
    : Spellcaster(name, "Warlock", 80, 100, new Staff(), new Summon(this), gameboard->getLocation(x, y)) {
        this->getSpellbook()->addSpell(spell_Fireball, new Fireball());
        this->getSpellbook()->addSpell(spell_IceBolt, new IceBolt());
        this->selectSpell(spell_Fireball);
}

Warlock::~Warlock() {}

void Warlock::conversion(Unit* owner) {
    skill->freeSlave();
    Unit::conversion(owner);
}