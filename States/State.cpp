#include "State.h"

State::State(const std::string& className, int hitPointsLimit, bool undead, int maxDistance) {
    this->className = className;
    this->hitPointsLimit = hitPointsLimit;
    this->hitPoints = hitPointsLimit;
    this->undead = undead;
    this->maxDistance = maxDistance;
    this->immutable = false;
}

State::~State() {
};

void State::ensureIsAlive() {
    if ( hitPoints == 0 ) {
        throw UnitIsDeadException();
    }
}

int State::getHitPointsLimit() {
    return this->hitPointsLimit;
}

int State::getHitPoints() {
    return this->hitPoints;
}

const std::string& State::getClassName() {
    return this->className;
}

bool State::getUndead() {
    return this->undead;
}

int State::getMaxDistance() {
    return this->maxDistance;
}

bool State::getImmutable() {
    return this->immutable;
}

int State::takeDamage(int dmg) {
    ensureIsAlive();

    if (dmg > this->hitPoints) {
        int tmp = this->hitPoints;
        this->hitPoints = 0;
        return tmp;
    }
    this->hitPoints -= dmg;
    return dmg;
}

int State::takeMagicDamage(int dmg) {
    return takeDamage(dmg);
}

int State::addHitPoints(int hp) {
    int total = hp + hitPoints;

    ensureIsAlive();

    if (total > hitPointsLimit) {
        int over = hitPointsLimit - hitPoints;
        hitPoints = hitPointsLimit;
        return over;
    }
    hitPoints = total;
    return hp;
}
