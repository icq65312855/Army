#include "Holy.h"

Holy::Holy(Unit* owner) : Skill(owner) {}
Holy::~Holy() {}

int Holy::modActionPoint(int actionPoint, Unit* target, Spell* spell) {
    if ( !spell->isHeal() && !target->getUndead() ) {
        return actionPoint/2;
    }

    return actionPoint;
}