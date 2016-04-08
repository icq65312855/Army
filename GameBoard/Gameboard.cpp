#include "Gameboard.h"

GameBoard::GameBoard(int size) : size(size) {
    board = new std::map<Location*, Unit*>();
}

GameBoard::~GameBoard() {
    delete board;
}

int GameBoard::getSize() {
    return size;
}

Location* GameBoard::getLocation(int x, int y) {
    std::map<Location*, Unit*>::iterator it;

    if ( x > size || y > size || x < 1 || y < 1) {
        throw OutOfRangeMap();
    }

    for (it = board->begin(); it != board->end(); it++) {
        if ( it->first->getX() == x && it->first->getY() == y) {
            return it->first;
        }
    }

    Location* loc = new Location(x,y);
    board->insert(std::pair<Location*, Unit*>(loc, NULL));

    return loc;
}

Unit* GameBoard::getUnit(Location* currentLoc) {
    std::map<Location*, Unit*>::iterator it = board->find(currentLoc);

    if ( it != board->end() ) {
        return it->second;
    }

    return NULL;
}

Location* GameBoard::move(Unit* unit, Location* targetLoc) {
    std::map<Location*, Unit*>::iterator it;

    it = board->find(targetLoc);
    if ( it != board->end() && it->second != NULL) {
        std::cout << "  location " << *targetLoc << " is owned by " << it->second->getName() << std::endl;
        return unit->getLocation();
        // throw BusyLocationException();
    }

    it->second = unit;

    it = board->find(unit->getLocation());
    if ( it != board->end() && it->second != NULL) {
        it->second = NULL;;
    }

    return targetLoc;
}

std::string GameBoard::normalizeText(std::string& strName) {
    std::string tmpString = strName;

    for (int i = tmpString.size(); i < 7; i++) {
        tmpString = tmpString + " ";
    }
    return tmpString;
}

// const std::string& GameBoard::unitName(int x, int y) {
//     Location* loc = getLocation(x, y);
//     Unit* unit = getUnit(loc);
//     std::string strName = "";

//     std::cout << *unit << std::endl;

//     if ( unit != NULL ) {
//         strName = unit->getName();
//         if ( strName.size() >= 7 ) {
//             strName = strName.substr(7);
//         } else {
//             strName = strName.substr(strName.size());
//         }
//     }
//     //normalizeText(strName);

//     return strName;
// }

// void GameBoard::viewBoard() {
//     for (int row = size; row > 0; row--) {
//         std:: cout << "| ";
//         for (int col = 1; col <= size; col++) {
//             std::cout << unitName(col, row) << " | ";
//         }
//         std::cout << std::endl;
//     }
// }

void GameBoard::view() {
    std::map<Location*, Unit*>::iterator it;

    for (it = board->begin(); it != board->end(); it++) {
        if ( it->second != NULL) {
            std::cout << *(it->second) << std::endl;
        }
    }
}

void GameBoard::freeLocation(Location* currentLoc) {
    std::map<Location*, Unit*>::iterator it;

    it = board->find(currentLoc);
    if ( it != board->end() && it->second != NULL) {
        it->second = NULL;
    }
}