#include "Wizard.h"

Wizard::Wizard(const std::string& name, int x, int y)
    : Spellcaster(name, "Wizard", 80, 100, new Staff(), new BattleMagic(this), gameboard->getLocation(x, y)) {
        this->getSpellbook()->addSpell(spell_Fireball, new Fireball());
        this->getSpellbook()->addSpell(spell_Heal, new Heal());
        this->selectSpell(spell_Fireball);
}

Wizard::~Wizard() {}