#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "../States/StateWerewolf.h"

class Werewolf : public Unit {
    public:
        Werewolf(const std::string& name, int x, int y);
        ~Werewolf();
};

#endif // WEREWOLF_H