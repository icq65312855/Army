#include "Rogue.h"

Rogue::Rogue(const std::string& name, int x, int y) 
    : Unit(name, 100, new Dagger(), "Rogue", new Impunity(this), gameboard->getLocation(x, y)) {}

Rogue::~Rogue() {}
