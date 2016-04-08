#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include "../Unit.h"
#include "../../Spells/Spellbook.h"
#include "../../Spells/Spell.h"
#include "../../Skills/Skill.h"
#include "../../Weapons/Staff.h"

class Spellcaster : public Unit {
    protected:
        int manaPointLimit;
        int manaPoint;
        Spellbook* spellbook;
    public:
        Spellcaster(const std::string& name, const std::string& className, int hitPointLimit, int manaPointLimit, Weapon* weapon, Skill* skill, Location* location, bool undead = false);
        virtual ~Spellcaster();

        const int getManaPoints() const;
        const int getManaPointsLimit() const;
        Spellbook* getSpellbook();
        Spell* getSpell();

        virtual void cast(Unit* target);
        void spendMana(int mana);
        int addMana(int mana);
        void addSpell(SpellName spellName, Spell* newSpell);
        void selectSpell(SpellName spellName);
        void changeSpell();
};

std::ostream& operator<<(std::ostream& out, const Spellcaster& unit);

#endif // SPELLCASTER_H