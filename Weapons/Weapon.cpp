#include "Weapon.h"

Weapon::Weapon() {
    attackRange = 1;
}

Weapon::~Weapon() {}

int Weapon::getDamage() {
    return this->damage;
}

int Weapon::getAttackRange() {
    return this->attackRange;
}