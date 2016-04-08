#include "Unit.h"

GameBoard* Unit::gameboard = new GameBoard(8);

Unit::Unit(const std::string& name, State* current, Skill* skill, Weapon* weapon, Location* location) : current(current), 
        name(name),
        skill(skill),
        weapon(weapon) {
    this->observers = new std::set<Unit*>();
    this->observables = new std::set<Unit*>();
    this->location = gameboard->move(this, location);
    this->mount = NULL;
}

Unit::Unit(const std::string& name, int hitPointsLimit, Weapon* weapon, const std::string className, Skill* skill, Location* location, bool undead, int maxDistance) 
    : name(name), skill(skill), weapon(weapon) {
    
    this->current = new State(className, hitPointsLimit, undead, maxDistance);
    this->observers = new std::set<Unit*>();
    this->observables = new std::set<Unit*>();
    this->location = gameboard->move(this, location);
    this->mount = NULL;
}

Unit::~Unit() {
    delete this->current;
    delete this->skill;
    delete this->weapon;
    delete this->location;
}

void Unit::ensureIsAlive() {
    current->ensureIsAlive();
}

bool Unit::ensureAttackRange(Unit* target) {
    if ( location->distance(target->getLocation()) > weapon->getAttackRange() ) {
        std::cout << "  too big range!" << std::endl;
        return false;
    }

    return true;
}

const std::string& Unit::getName() const {
    return this->name;
}

const std::string& Unit::getClassName() const {
    return current->getClassName();
}

int Unit::getHitPoints() const {
    return current->getHitPoints();
}

int Unit::getHitPointsLimit() const {
    return current->getHitPointsLimit();
}

const int Unit::getManaPointsLimit() const {
    return 0;
}

int Unit::getDamage() const {
    return weapon->getDamage();
}

Skill* Unit::getSkill() const {
    return this->skill;
}

const std::set<Unit*>& Unit::getObservers() const {
    return *observers;
}

const std::set<Unit*>& Unit::getObservables() const {
    return *observables;
}

State* Unit::getCurrent() const {
    return this->current;
}

bool Unit::getUndead() {
    return this->current->getUndead();
}

bool Unit::getImmutable() {
    return this->current->getImmutable();
}

Weapon* Unit::getWeapon() {
    return this->weapon;
}

Mount* Unit::getMount() const {
    return this->mount;
}

Location* Unit::getLocation() const {
    return location;
}

GameBoard* Unit::getGameboard() {
    return gameboard;
}

int Unit::getMaxDistance() {
    if ( this->mount != NULL ) {
        if ( current->getMaxDistance() < mount->getMaxDistance() ) {
            return mount->getMaxDistance();
        }
    }

    return current->getMaxDistance();
}

void Unit::conversion(Unit* enemy) {
    this->current = enemy->getSkill()->conversionState(this);
    this->skill = enemy->getSkill()->conversionSkill(this);
    this->weapon = enemy->getSkill()->conversionWeapon(this);

    std::cout << this->getName() << " conversion in " << current->getClassName() << std::endl;
}

int Unit::takeDamage(int dmg) {
    int damageDone;

    damageDone = current->takeDamage(dmg);
    std::cout << "  " << this->getName() << " take " << damageDone << " damage" << std::endl;

    if ( this->getHitPoints() == 0 ) {
        this->notifyObservers();
        this->notifyObservables();
        gameboard->freeLocation(location);
    }

    return damageDone;
}

int Unit::takeMagicDamage(int dmg) {
    int damageDone;

    damageDone = current->takeDamage(skill->modTakeMagicDamage(dmg));
    std::cout << "  " << this->getName() << " take " << damageDone << " magic damage" << std::endl;

    return damageDone;
}

void Unit::addHitPoints(int hp) {
    std::cout << "  " << this->getName() << " healed on " << current->addHitPoints(hp) << " hp" << std::endl;
}

void Unit::spendMana(int mana) {}

void Unit::attack(Unit* target) {
   std::cout << this->getName() << " attacked " << target->getName() << std::endl;
   if ( !ensureAttackRange(target) ) {
        return;
    }
    skill->modAttack(this->getDamage(),target);
}

void Unit::counterAttack(Unit* target) {
    std::cout << "  " << this->getName() << " counter attacked " << target->getName() << std::endl;
    if ( !ensureAttackRange(target) ) {
        return;
    }
    skill->modCounterAttack(this->getDamage()/2,target);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getName() << " [";
    out << unit.getClassName();
    out << ", HP (" << unit.getHitPoints() << " / " << unit.getHitPointsLimit();
    out << "), " << unit.getDamage() << " dmg]";
    out << ", " << *(unit.getLocation());

    std::set<Unit*> observers = unit.getObservers();
    if ( observers.size() == 0 ) {
        return out;
    }

    std::set<Unit*>::iterator it;
    out << " Observers ( ";
    for (it = observers.begin(); it != observers.end(); it++) {
        out << (*it)->getName() << " ";
    }
    out << ")";

    return out; 
}

void Unit::activateSkill() {
    skill->action();
}

void Unit::addObserver(Unit* observer) {
    this->observers->insert(observer);
}

void Unit::addObservable(Unit* observable) {
    this->observables->insert(observable);
}

void Unit::deleteObserver(Unit* observer) {
    this->observers->erase(observer);
}

void Unit::deleteObservable(Unit* observable) {
    this->observables->erase(observable);
}

void Unit::notifyObservers() {
    std::set<Unit*>::iterator it;

    for (it = this->observers->begin(); it != this->observers->end(); it++) {
        (*it)->addHitPoints(this->getHitPointsLimit()/5);
        (*it)->deleteObservable(this);
    }
}

void Unit::notifyObservables() {
    std::set<Unit*>::iterator it;

    for (it = this->observables->begin(); it != this->observables->end(); it++) {
        (*it)->deleteObserver(this);
    }
}

bool Unit::ensureDistance(int distance) {
    if ( this->getMaxDistance() < distance ) {
        std::cout << "Too long distance!" << std::endl;
        return false;
    }

    return true;
}

void Unit::move(int x, int y) {
    std::cout << getName() << " moving to (" << x << ", " << y << ")" << std::endl;
    location = gameboard->move(this, gameboard->getLocation(x,y));
}

void Unit::left(int distance) {
    if (ensureDistance(distance)) {
        move(location->getX()-distance,location->getY());
    }
}

void Unit::right(int distance) {
    if (ensureDistance(distance)) {
        move(location->getX()+distance,location->getY());
    }
}

void Unit::up(int distance) {
    if (ensureDistance(distance)) {
        move(location->getX(),location->getY()+distance);
    }
}

void Unit::down(int distance) {
    if (ensureDistance(distance)) {
        move(location->getX(),location->getY()-distance);
    }
}

void Unit::toMount(Mount* newMount) {
    this->mount = newMount;
}
void Unit::dismount() {
    this->mount = NULL;
}