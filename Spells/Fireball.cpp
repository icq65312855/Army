#include "Fireball.h"

Fireball::Fireball()
    : Spell(10, 30, "Fireball", 5) {}

Fireball::~Fireball() {}

void Fireball::action(Unit* target, Unit* caster) {
    if ( Spell::ensureIsDistance(target,caster) ) {
        target->takeMagicDamage(caster->getSkill()->modActionPoint(actionPoint,target,this));
    }
}