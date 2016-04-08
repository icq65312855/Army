#include "Spellbook.h"

void Spellbook::ensureIsSpell() {
    if ( this->book->empty() ) {
        throw SpellbookIsEmpty();
    }
    if (this->spell == this->book->end()) {
        throw SpellIsUnavailable();
    }
}

Spellbook::Spellbook() {
    book = new std::map<SpellName, Spell*>();
}

Spellbook::~Spellbook() {
    delete book;
}

Spell* Spellbook::getSpell() {
    ensureIsSpell();
    return spell->second;
}

void Spellbook::addSpell(SpellName spellName, Spell* newSpell) {
    book->insert(std::pair<SpellName, Spell*>(spellName, newSpell));
}

void Spellbook::selectSpell(SpellName spellName) {
    this->spell = book->find(spellName);
    ensureIsSpell();
}

void Spellbook::changeSpell() {
    this->spell++;
    if (this->spell == this->book->end()) {
        this->spell = this->book->begin();
    }
    ensureIsSpell();
}