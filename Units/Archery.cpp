#include "Archery.h"

Archery::Archery(const std::string& name, int x, int y) 
    : Unit(name, new StateArchery(), new Skill(this), new Bow(), gameboard->getLocation(x, y)) {}

Archery::~Archery() {}
