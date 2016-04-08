#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include "../Units/Unit.h"
#include <cmath>

class Unit;

class Location {
    private:
        int x;
        int y;
    public:
        Location(int x=1, int y=1);
        Location(Unit* unit);
        ~Location();

        int getX() const;
        int getY() const;

        int distance(const Location* other) const;
        bool operator==(const Location& other) const;
        bool operator!=(const Location& other) const;
};

std::ostream& operator<<(std::ostream& out, const Location& location);

#endif // LOCATION_H