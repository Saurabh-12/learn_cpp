#include<iostream>
#include<memory>
#include "VehicleType.h"
#include "Vehicle.h"
#include "AllVehicleClass.cpp"

class VehicleFactory {
public:
    static std::unique_ptr<Vehicle> Create(VEHICLE_TYPE type, int numGears, ENGINE engine) {
        switch (type) {
            case VEHICLE_TYPE::BIKE: return std::make_unique<Bike>(numGears, engine);
            case VEHICLE_TYPE::CAR: return std::make_unique<Car>(numGears, engine);
            case VEHICLE_TYPE::TRUCK: return std::make_unique<Truck>(numGears, engine);
            default: return nullptr;
        }
    }
};

int main() {

    std::unique_ptr<Vehicle> vehicle = VehicleFactory::Create(VEHICLE_TYPE::TRUCK, 5, ENGINE::HP_200);
    vehicle->moveForward();
    vehicle->moveBackward();
    vehicle->turnLeft();
    vehicle->turnRight();
    vehicle->applyFrontBrake();
    vehicle->applyBackBrake();
    vehicle->loadItems();

    return 0;
}