#ifndef ARCHERY_H
#define ARCHERY_H

#include "Unit.h"
#include "../States/StateArchery.h"
#include "../Skills/Skill.h"
#include "../Weapons/Bow.h"

class Archery : public Unit {
    public:
        Archery(const std::string& name, int x, int y);
        ~Archery();
};

#endif // ARCHERY_H