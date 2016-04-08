#include "BattleMagic.h"

BattleMagic::BattleMagic(Unit* owner) : Skill(owner) {}
BattleMagic::~BattleMagic() {}

int BattleMagic::modActionPoint(int actionPoint, Unit* target, Spell* spell) {
    if ( spell->isHeal() ) {
        return actionPoint/2;
    }

    return actionPoint;
}