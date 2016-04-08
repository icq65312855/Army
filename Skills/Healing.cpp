#include "Healing.h"

Healing::Healing(Unit* owner) : Skill(owner) {}
Healing::~Healing() {}

int Healing::modActionPoint(int actionPoint, Unit* target, Spell* spell) {
    if ( !spell->isHeal() ) {
        return actionPoint/2;
    }

    return actionPoint;
}