#include "Spellcaster.h"
#include "../../Exceptions.h"

Spellcaster::Spellcaster(const std::string& name, const std::string& className, int hitPointLimit, int manaPointLimit, Weapon* weapon, Skill* skill, Location* location, bool undead)
            : Unit(name, hitPointLimit, weapon, className, skill, location, undead) {
        this->spellbook = new Spellbook();
        this->manaPointLimit = manaPointLimit;
        this->manaPoint = manaPointLimit;
    }

Spellcaster::~Spellcaster() {};

const int Spellcaster::getManaPoints() const {
    return this->manaPoint;
}

const int Spellcaster::getManaPointsLimit() const {
    return this->manaPointLimit;
}

Spellbook* Spellcaster::getSpellbook() {
    return this->spellbook;
}

Spell* Spellcaster::getSpell() {
    return this->spellbook->getSpell();
}

void Spellcaster::spendMana(int mana) {
    if ( mana > this->manaPoint) {
        throw OutOfManaException();
    }
    this->manaPoint -= mana;
}

void Spellcaster::cast(Unit* target) {
    target->ensureIsAlive();
    Spell* spell = this->getSpell();

    std::cout << this->getName() << " use cast " << spell->getSpellName();
    std::cout << " on target " << target->getName() << std::endl;

    this->spendMana(spell->getCost());
    spell->action(target, this);
}

void Spellcaster::addSpell(SpellName spellName, Spell* newSpell) {
    spellbook->addSpell(spellName, newSpell);
}

void Spellcaster::selectSpell(SpellName spellName) {
    spellbook->selectSpell(spellName);
    std::cout << this->getName() << " choose spell: " << spellbook->getSpell()->getSpellName() << std::endl;
}

void Spellcaster::changeSpell() {
    spellbook->changeSpell();
    std::cout << this->getName() << " choose spell: " << spellbook->getSpell()->getSpellName() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Spellcaster& unit) {
    out << unit.getName() << " [";
    out << unit.getClassName();
    out << ", HP (" << unit.getHitPoints() << " / " << unit.getHitPointsLimit();
    out << ", MP (" << unit.getManaPoints() << " / " << unit.getManaPointsLimit();
    out << "), " << unit.getDamage() << " dmg]";
    out << ", " << *(unit.getLocation());

    std::set<Unit*> observers = unit.getObservers();
    if ( observers.size() == 0 ) {
        return out;
    }

    std::set<Unit*>::iterator it;
    out << " Observers ( ";
    for (it = observers.begin(); it != observers.end(); it++) {
        out << (*it)->getName() << " ";
    }
    out << ")";

    return out; 
}