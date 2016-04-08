#include "Mount.h"

Mount::Mount(int maxDistance) : maxDistance(maxDistance) {

}

Mount::~Mount() {}

int Mount::getMaxDistance() {
    return this->maxDistance;
}