#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <iostream>
#include "Spell.h"
#include <map>
#include "../Exceptions.h"
#include "FireBall.h"
#include "IceBolt.h"
#include "Heal.h"

enum SpellName { 
    spell_Fireball,
    spell_Windstorm,
    spell_LightningBolt,
    spell_IceBolt,
    spell_Heal 
};

class Spellbook {
    protected:
        std::map<SpellName, Spell*>::iterator spell;
        std::map<SpellName, Spell*>* book;
        void ensureIsSpell();
    public:
        Spellbook();
        virtual ~Spellbook();
        Spell* getSpell();
        void addSpell(SpellName spellName, Spell* newSpell);
        void selectSpell(SpellName spellName);
        void changeSpell();

};

#endif // SPELLBOOK_H