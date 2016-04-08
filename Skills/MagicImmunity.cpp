#include "MagicImmunity.h"

MagicImmunity::MagicImmunity(Unit* owner) : Skill(owner) {}
MagicImmunity::~MagicImmunity() {}

int MagicImmunity::modTakeMagicDamage(int damage) {
    return 0;
}