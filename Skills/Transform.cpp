#include "Transform.h"

Transform::Transform(Unit* owner, State* altState, Weapon* altWeapon) : Skill(owner) {
    this->altState = altState;
    this->altWeapon = altWeapon;
}

Transform::~Transform() {
    delete altState;
    delete altWeapon;
}

State* Transform::conversionState(Unit* unit) {
    if ( owner == unit ) {
        return this->altState;
    }
    if ( !unit->getImmutable() ) {
        return new StateWerewolf();
    }
    return unit->getCurrent();
}

Skill* Transform::conversionSkill(Unit* unit) {
    if ( owner == unit ) {
        return this;
    }
    if ( !unit->getImmutable() ) {
        return new Transform(unit, new StateHuman(), new Sword());
    }
    return unit->getSkill();
}

Weapon* Transform::conversionWeapon(Unit* unit) {
    if ( owner == unit ) {
        return this->altWeapon;
    }
    if ( !unit->getImmutable() ) {
        return new Claws();
    }
    return unit->getWeapon();
}

void Transform::action(Unit* target) {
    int perCurrentHp;
    int perAltHp;
    State* tmpState = owner->getCurrent();
    Weapon* tmpWeapon = owner->getWeapon();

    perCurrentHp = tmpState->getHitPoints()*100/tmpState->getHitPointsLimit();
    perAltHp = altState->getHitPoints()*100/altState->getHitPointsLimit();

    if ( perCurrentHp < perAltHp ) {
        altState->takeDamage(altState->getHitPoints()*(perAltHp - perCurrentHp)/100);
    } else if (perCurrentHp > perAltHp) {
        altState->addHitPoints(altState->getHitPoints()*(perCurrentHp - perAltHp)/100);
    }

    owner->conversion(owner);

    this->altState = tmpState;
    this->altWeapon = tmpWeapon;

    std::cout << "  " << *owner << std::endl;
}

void Transform::modAttack(int damage, Unit* target) {
    if ( target->getHitPoints() <= damage ) {
        target->conversion(owner);
        return;
    }

    int damageDone = target->takeDamage(damage);
    target->counterAttack(owner);
}

void Transform::modCounterAttack(int damage, Unit* target) {
    int damageDone = target->takeDamage(damage);

    if ( target->getHitPoints() == 0 ) {
        target->conversion(owner);
    }
}
