#include "Vampiric.h"

Vampiric::Vampiric(Unit* owner) : Skill(owner) {}
Vampiric::~Vampiric() {}

State* Vampiric::conversionState(Unit* unit) {
    if ( owner == unit ) {
        return owner->getCurrent();
    }
    if ( !unit->getImmutable() ) {
        return new StateVampire();
    }
    return unit->getCurrent();
}

Skill* Vampiric::conversionSkill(Unit* unit) {
    if ( owner == unit ) {
        return owner->getSkill();
    }
    if ( !unit->getImmutable() ) {
        return new Vampiric(unit);
    }
    return unit->getSkill();
}

Weapon* Vampiric::conversionWeapon(Unit* unit) {
    if ( owner == unit ) {
        return owner->getWeapon();
    }
    if ( !unit->getImmutable() ) {
        return new Claws();
    }
    return unit->getWeapon();
}

void Vampiric::modAttack(int damage, Unit* target) {
    int damageDone;

    damageDone = target->takeDamage(damage);
    owner->addHitPoints(damageDone/2);

    if ( target->getHitPoints() == 0 ) {
        target->conversion(owner);
        return;
    }
    target->counterAttack(owner);
}

void Vampiric::modCounterAttack(int damage, Unit* target) {
    int damageDone;

    damageDone = target->takeDamage(damage);
    owner->addHitPoints(damageDone/2);

    if ( target->getHitPoints() == 0 ) {
        target->conversion(owner);
    }
}
