#include <iostream>
#include "Exceptions.h"
#include "GameBoard/GameBoard.h"
#include "Units/Soldier.h"
#include "Units/Archery.h"
#include "Units/Rogue.h"
#include "Units/Berserker.h"
#include "Units/Vampire.h"
#include "Units/Werewolf.h"
#include "Units/Demon.h"
#include "Units/Spellcasters/Wizard.h"
#include "Units/Spellcasters/Healer.h"
#include "Units/Spellcasters/Priest.h"
#include "Units/Spellcasters/Warlock.h"
#include "Units/Spellcasters/Necromancer.h"
#include "Mounts/Horse.h"

int main() {
    Soldier* soldier1 = new Soldier("Jim",1,1);
    Soldier* soldier2 = new Soldier("Ivan",2,1);
    Archery* archer1 = new Archery("Robin Good",3,1);
    Rogue* rogue1 = new Rogue("Solovey",4,1);
    Berserker* berserker1 = new Berserker("Halk",6,1);
    Vampire* vampire1 = new Vampire("Drakula",1,3);
    Werewolf* werewolf1 = new Werewolf("Jake",3,3);
    Wizard* wizard1 = new Wizard("Gendalf",1,8);
    Healer* healer1 = new Healer("Tereza",3,8);
    Priest* priest1 = new Priest("Bishop",5,8);
    Warlock* warlock1 = new Warlock("Kreol",8,8);
    Necromancer* necromancer1 = new Necromancer("Fess",1,4);
    Necromancer* necromancer2 = new Necromancer("Necros",4,4);
    Horse* horse1 = new Horse();

    Unit::getGameboard()->view();

    std::cout << std::endl;
    std::cout << "Battle in progress..." << std::endl;
    std::cout << std::endl;

    //soldier
    soldier1->attack(soldier2);
    soldier2->attack(vampire1);
    soldier2->activateSkill();
    soldier2->attack(vampire1);
    soldier1->attack(berserker1);
    //archer
    archer1->attack(werewolf1);
    archer1->attack(warlock1);
    //rogue
    rogue1->attack(soldier1);
    rogue1->attack(vampire1);
    rogue1->attack(warlock1);
    rogue1->attack(warlock1);
    //berserker
    berserker1->toMount(horse1);
    berserker1->up(1);
    berserker1->left(3);
    // berserker1->left(1);
    berserker1->attack(werewolf1);
    //werewolf
    werewolf1->activateSkill();
    werewolf1->down(1);
    werewolf1->right(1);
    werewolf1->attack(rogue1);
    werewolf1->attack(rogue1);
    //necromancer
    necromancer1->right(1);
    necromancer1->right(1);
    necromancer1->up(1);
    necromancer1->up(1);
    necromancer1->attack(rogue1);
    necromancer1->cast(warlock1);
    necromancer2->attack(warlock1);
    //vampire
    vampire1->attack(werewolf1);
    std::cout << *rogue1 << std::endl;
    vampire1->attack(wizard1);
    //wizard
    wizard1->selectSpell(spell_Fireball);
    wizard1->down(1);
    wizard1->down(1);
    wizard1->right(1);
    wizard1->cast(berserker1);
    wizard1->cast(werewolf1);
    wizard1->cast(vampire1);
    wizard1->cast(necromancer1);
    wizard1->changeSpell();
    //healer
    healer1->cast(wizard1);
    healer1->changeSpell();
    healer1->cast(vampire1);
    //priest
    priest1->cast(necromancer1);
    priest1->cast(soldier1);
    priest1->cast(werewolf1);
    priest1->changeSpell();
    priest1->cast(rogue1);
    //warlock
    warlock1->cast(rogue1);
    warlock1->left(1);
    warlock1->activateSkill();
    warlock1->getSkill()->demon()->attack(priest1);
    Demon* demon1 = warlock1->getSkill()->demon();
    
    werewolf1->activateSkill();

    std::cout << std::endl;
    std::cout << "...Battle is over" << std::endl;
    std::cout << std::endl;

    Unit::getGameboard()->view();

    delete soldier1;
    delete soldier2;
    delete archer1;
    delete rogue1;
    delete vampire1;
    delete berserker1;
    delete werewolf1;
    delete wizard1;
    delete healer1;
    delete priest1;
    delete warlock1;
    delete necromancer1;
    delete necromancer2;

    return 0;
}
