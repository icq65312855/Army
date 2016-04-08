#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, int x, int y) 
    : Unit(name, new StateHuman(), new Transform(this, new StateWerewolf(), new Claws()), new Sword(), gameboard->getLocation(x, y)) {}

Werewolf::~Werewolf() {}
