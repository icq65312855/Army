#include "Necromancer.h"

Necromancer::Necromancer(const std::string& name, int x, int y)
    : Spellcaster(name, "Necromancer", 80, 100, new Staff(), new Observer(this), gameboard->getLocation(x, y), true) {
        this->getSpellbook()->addSpell(spell_Fireball, new Fireball());
        this->getSpellbook()->addSpell(spell_IceBolt, new IceBolt());
        this->selectSpell(spell_Fireball);
}

Necromancer::~Necromancer() {}

void Necromancer::conversion(Unit* owner) {
    Unit::notifyObservables();
    Unit::conversion(owner);
}