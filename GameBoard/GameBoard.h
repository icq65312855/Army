#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <map>
#include "Location.h"
#include "../Exceptions.h"
#include "../Units/Unit.h"
#include "Location.h"

class Unit;
class Location;

class GameBoard {
    private:
        int size;
        std::map<Location*, Unit*>* board;

        std::string normalizeText(std::string& strName);
        const std::string& unitName(int x, int y);
    public:
        GameBoard(int size);
        ~GameBoard();

        int getSize();
        Location* getLocation(int x, int y);
        Unit* getUnit(Location* currentLoc);

        Location* move(Unit* unit, Location* targetLoc);
        void view();
        void viewBoard();
        void freeLocation(Location* currentLoc);
};

#endif // GAMEBOARD_H