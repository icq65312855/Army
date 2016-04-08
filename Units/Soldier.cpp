#include "Soldier.h"

Soldier::Soldier(const std::string& name, int x, int y) 
    : Unit(name, 120, new Sword(), "Soldier", new Improving(this), gameboard->getLocation(x, y)) {
}

Soldier::~Soldier() {}
