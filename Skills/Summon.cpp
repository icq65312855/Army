#include "Summon.h"

Summon::Summon(Unit* owner) : Skill(owner) {
    slave = NULL;
}

Summon::~Summon() {
    if ( slave != NULL ) {
        delete slave;
    }
}

Demon* Summon::demon() {
    if ( slave == NULL ) {
        throw DemonNotFindException();
    }
    return slave;
}

void Summon::action(Unit* target) {
    if ( slave != NULL ) {
        return;
    }
    owner->spendMana(owner->getManaPointsLimit()/2);
    slave = new Demon(owner, owner->getLocation()->getX()+1, owner->getLocation()->getY());
    std::cout << owner->getName() << " summoned the demon!" << std::endl;
}

void Summon::freeSlave() {
    if ( slave == NULL ) {
        return;
    }
    
    std::cout << owner->getName() << " freed the demon!" << std::endl;
    delete slave;
    slave = NULL;
}
