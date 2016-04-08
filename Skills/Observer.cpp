#include "Observer.h"

Observer::Observer(Unit* owner) : Skill(owner) {}
Observer::~Observer() {}

void Observer::modAttack(int damage, Unit* target) {
    Skill::modAttack(damage, target);
    owner->addObservable(target);
    target->addObserver(owner);

}

void Observer::modCounterAttack(int damage, Unit* target) {
    Skill::modCounterAttack(damage, target);
    owner->addObservable(target);
    target->addObserver(owner);
}

int Observer::modActionPoint(int actionPoint, Unit* target, Spell* spell) {
    if ( !spell->isHeal() ) {
        owner->addObservable(target);
        target->addObserver(owner);
    }
    return actionPoint;
}
