#include "Location.h"

Location::Location(int x, int y) {
    this->x = x;
    this->y = y;
};

Location::Location(Unit* unit) {
    this->x = unit->getLocation()->getX();
    this->y = unit->getLocation()->getY();
}

Location::~Location() {

};

int Location::getX() const {
    return this->x;
};

int Location::getY() const {
    return this->y;
};

int Location::distance(const Location* other) const {
    return hypot(this->x-other->x, this->y-other->y);
};

bool Location::operator==(const Location& other) const {
    return this->x == other.x && this->y == other.y;
};

bool Location::operator!=(const Location& other) const {
    return this->x != other.x || this->y != other.y;
};

std::ostream& operator<<(std::ostream& out, const Location& location) {
    out << '(' << location.getX() << ", " << location.getY() << ')';
    return out;
};