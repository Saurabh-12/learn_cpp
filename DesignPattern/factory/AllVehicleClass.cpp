#include<iostream>
#include "Vehicle.h"

class Truck : public Vehicle
{
public:
    Truck(int numGears, ENGINE engine) : Vehicle(HANDLER::STEERING, engine, numGears, true, 6) {}

    void moveForward() override
    {
        std::cout << "accelerate using paddle" << std::endl;
    }

    bool moveBackward() override
    {
        std::cout << "switch to reverse gear and accelerate" << std::endl;
        return true;
    }

    void turnLeft() override
    {
        std::cout << "move steering wheel to 45 degrees clockwise" << std::endl;
    }

    void turnRight() override
    {
        std::cout << "move steering wheel to 45 degrees anti-clockwise" << std::endl;
    }

    void applyFrontBrake() override
    {
        std::cout << "apply Brake on both front tyres" << std::endl;
    }

    void applyBackBrake() override
    {
        std::cout << "apply Brake on both back tyres" << std::endl;
    }

    bool loadItems() override
    {
        std::cout << "Opened storage door compartment to load items" << std::endl;
        return false;
    }
};

class Bike : public Vehicle
{
public:
    Bike(int numGears, ENGINE engine) : Vehicle(HANDLER::HANDLE, engine, numGears, false, 2) {}

    void moveForward() override
    {
        std::cout << "accelerate using handle" << std::endl;
    }

    bool moveBackward() override
    {
        std::cout << "can't move backwards" << std::endl;
        return false;
    }

    void turnLeft() override
    {
        std::cout << "move handle to 45 degrees clockwise" << std::endl;
    }

    void turnRight() override
    {
        std::cout << "move handle to 45 degrees anti-clockwise" << std::endl;
    }

    void applyFrontBrake() override
    {
        std::cout << "apply disk brake on front tyre" << std::endl;
    }

    void applyBackBrake() override
    {
        std::cout << "apply disk brake on back tyre" << std::endl;
    }

    bool loadItems() override
    {
        std::cout << "can't load items" << std::endl;
        return false;
    }
};

class Car : public Vehicle
{
public:
    Car(int numGears, ENGINE engine) : Vehicle(HANDLER::STEERING, engine, numGears, true, 4) {}

    void moveForward() override
    {
        std::cout << "accelerate using paddle" << std::endl;
    }

    bool moveBackward() override
    {
        std::cout << "switch to reverse gear and accelerate" << std::endl;
        return true;
    }

    void turnLeft() override
    {
        std::cout << "move steering wheel to 45 degrees clockwise" << std::endl;
    }

    void turnRight() override
    {
        std::cout << "move steering wheel to 45 degrees anti-clockwise" << std::endl;
    }

    void applyFrontBrake() override
    {
        std::cout << "apply brake on both front tyres" << std::endl;
    }

    void applyBackBrake() override
    {
        std::cout << "apply brake on both back tyres" << std::endl;
    }

    bool loadItems() override
    {
        std::cout << "can't load items" << std::endl;
        return false;
    }
};