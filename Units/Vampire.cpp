#include "Vampire.h"

Vampire::Vampire(const std::string& name, int x, int y) 
    : Unit(name, new StateVampire(), new Vampiric(this), new Fangs(), gameboard->getLocation(x, y)) {}

Vampire::~Vampire() {}
