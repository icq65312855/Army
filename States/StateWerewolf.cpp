#include "StateWerewolf.h"

StateWerewolf::StateWerewolf() :
    State("Werewolf", 240, false, 2) {
        this->immutable = true;
    }

StateWerewolf::~StateWerewolf() {}

int StateWerewolf::takeMagicDamage(int dmg) {
    return State::takeDamage(2*dmg);
}