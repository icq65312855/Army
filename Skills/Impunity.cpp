#include "Impunity.h"

Impunity::Impunity(Unit* owner) : Skill(owner) {}
Impunity::~Impunity() {}

void Impunity::modAttack(int damage, Unit* target) {
    target->takeDamage(damage);
} 