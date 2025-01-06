#include "HANDLER.h"
#include "ENGINE.h"

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
private:
    HANDLER handler;
    ENGINE engine;
    int numGears;
    bool reverseGear;
    int numTyres;

public:
    Vehicle(HANDLER handler, ENGINE engine, int numGears, bool reverseGear, int numTyres)
        : handler(handler), engine(engine), numGears(numGears), reverseGear(reverseGear), numTyres(numTyres) {}

    virtual void moveForward() = 0;
    virtual bool moveBackward() = 0;
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void applyFrontBrake() = 0;
    virtual void applyBackBrake() = 0;
    virtual bool loadItems() = 0;

};

#endif