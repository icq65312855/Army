#include "IceBolt.h"

IceBolt::IceBolt()
    : Spell(10, 30, "Ice bolt", 5) {}

IceBolt::~IceBolt() {}

void IceBolt::action(Unit* target, Unit* caster) {
    if ( Spell::ensureIsDistance(target,caster) ) {
        target->takeMagicDamage(caster->getSkill()->modActionPoint(actionPoint,target,this));
    }    
}