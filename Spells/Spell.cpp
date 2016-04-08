#include "Spell.h"

Spell::Spell(int cost, int actionPoint, const std::string& name, int maxDistance) :
    cost(cost), 
    actionPoint(actionPoint), 
    name(name),
    maxDistance(maxDistance) {}

Spell::~Spell() {}

int Spell::getCost() {
    return this->cost;
}

int Spell::getActionPoint() {
    return this->actionPoint;
}

bool Spell::isHeal() {
    return false;
}

const int Spell::getMaxDistance() {
    return maxDistance;
}

bool Spell::ensureIsDistance(Unit* target, Unit* caster) {
    if ( caster->getLocation()->distance(target->getLocation()) > this->getMaxDistance() ) {
        std::cout << "Too long distance! " << std::endl;
        return false;
    }

    return true;
}

const std::string& Spell::getSpellName() {
    return this->name;
}