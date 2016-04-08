#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "../States/StateVampire.h"

class Vampire : public Unit {
    public:
        Vampire(const std::string& name, int x, int y);
        virtual ~Vampire();
};

#endif // VAMPIRE_H