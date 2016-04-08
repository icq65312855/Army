#include "Berserker.h"

Berserker::Berserker(const std::string& name, int x, int y)
    : Unit(name, 120, new Axe(), "Berserker", new MagicImmunity(this), gameboard->getLocation(x, y)) {}

Berserker::~Berserker() {}
