#include "Skill.h"

Skill::Skill(Unit* owner) : owner(owner) {}

Skill::~Skill() {}

void Skill::modAttack(int damage, Unit* target) {
    target->takeDamage(damage);
    target->counterAttack(owner);
}

int Skill::modTakeMagicDamage(int damage) {
    return damage;
}

int Skill::modActionPoint(int actionPoint, Unit* target, Spell* spell) {
    return actionPoint;
}

void Skill::modCounterAttack(int damage, Unit* target) {
    target->takeDamage(damage);
}

void Skill::action(Unit* target) {}

State* Skill::conversionState(Unit* unit) {
    return unit->getCurrent();
}

Skill* Skill::conversionSkill(Unit* unit) {
    return unit->getSkill();
}

Weapon* Skill::conversionWeapon(Unit* unit) {
    return unit->getWeapon();
}

Demon* Skill::demon() {
    throw DemonNotFindException();
    return NULL;
}

void Skill::freeSlave() {}

