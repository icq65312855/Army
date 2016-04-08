#include "Demon.h"

Demon::Demon(Unit* master, int x, int y) 
    : Unit("Demon", 130, new Spike(), "Demon", new Skill(this), gameboard->getLocation(x, y)), master(master) {}

Demon::~Demon() {}

int Demon::takeDamage(int dmg) {
    int damageDone;

    damageDone = Unit::takeDamage(dmg);
    if ( this->getHitPoints() == 0 ) {
        master->getSkill()->freeSlave();
    }
    return damageDone;
}
