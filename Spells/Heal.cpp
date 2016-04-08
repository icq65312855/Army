#include "Heal.h"

Heal::Heal()
    : Spell(10, 30, "Heal", 5) {}

Heal::~Heal() {}

bool Heal::isHeal() {
    return true;
}

void Heal::action(Unit* target, Unit* caster) {
    if ( Spell::ensureIsDistance(target,caster) ) {
        target->addHitPoints(caster->getSkill()->modActionPoint(actionPoint,target,this));
    }
}