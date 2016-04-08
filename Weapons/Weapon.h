#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
    protected:
        int attackRange;
        int damage;
    public:
        Weapon();
        virtual ~Weapon();

        int getDamage();
        int getAttackRange();
};

#endif // WEAPON_H