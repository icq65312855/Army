#include "Improving.h"

Improving::Improving(Unit* owner) : Skill(owner) {
    this->altWeapon = new Bow();
    this->altState = new StateArchery();
}

Improving::~Improving() {
    if ( altWeapon != owner->getWeapon() ) {
        delete altWeapon;
    }
    if ( altState != owner->getCurrent() ) {
        delete altState;
    }
}

Weapon* Improving::conversionWeapon(Unit* unit) {
    if ( owner == unit ) {
        return this->altWeapon;
    }
    return unit->getWeapon();
}

State* Improving::conversionState(Unit* unit) {
    if ( owner == unit ) {
        return this->altState;
    }
    return unit->getCurrent();
}

void Improving::action(Unit* target) {
    owner->conversion(owner);
}
