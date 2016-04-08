#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <set>
#include "../States/State.h"
#include "../Skills/Skill.h"
#include "../Gameboard/Location.h"
#include "../Gameboard/Gameboard.h"
#include "../Weapons/Weapon.h"
#include "../Mounts/Mount.h"

class State;
class Skill;
class GameBoard;
class Location;

class Unit {
    protected:
        std::string name;
        State* current;
        Skill* skill;
        Weapon* weapon;
        std::set<Unit*>* observers;
        std::set<Unit*>* observables;
        Location* location;
        Mount* mount;
        static GameBoard* gameboard;
    public:
        virtual void ensureIsAlive();
        Unit(const std::string& name, int hitPointsLimit, Weapon* weapon, const std::string className, Skill* skill, Location* location, bool undead = false, int maxDistance = 1);
        Unit(const std::string& name, State* current, Skill* skill, Weapon* weapon, Location* location);
        virtual ~Unit();

        const std::string& getName() const;
        const std::string& getClassName() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        virtual const int getManaPointsLimit() const;
        int getDamage() const;
        Skill* getSkill() const;
        State* getCurrent() const;
        Mount* getMount() const;
        const std::set<Unit*>& getObservers() const;
        const std::set<Unit*>& getObservables() const;
        bool getUndead();
        bool getImmutable();
        Weapon* getWeapon();
        Location* getLocation() const;
        static GameBoard* getGameboard();
        int getMaxDistance();

        bool ensureDistance(int distance);
        bool ensureAttackRange(Unit* target);

        virtual void conversion(Unit* enemy);

        virtual int takeDamage(int dmg);
        virtual int takeMagicDamage(int dmg);
        void addHitPoints(int hp);
        virtual void spendMana(int mana);

        virtual void attack(Unit* target);
        virtual void counterAttack(Unit* target);
        void activateSkill();

        void addObserver(Unit* observer);
        void deleteObserver(Unit* observer);
        void addObservable(Unit* observable);
        void deleteObservable(Unit* observable);
        void notifyObservers();
        void notifyObservables();

        void move(int x, int y);
        void left(int distance);
        void right(int distance);
        void up(int distance);
        void down(int distance);

        void toMount(Mount* newMount);
        void dismount();
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H