// This example is just for understanding classes. Don't implement.

#include <array>
#include <iostream>

class Wheel {};

class Door {};

class Car {
   public:
    void openDoor();

    void startEngine() {
        igniteFuel();
    }

    void turnWheel() {
        turnAssist();
    }

   private:
    void igniteFuel();
    void turnAssist();

    std::array<Wheel, 4> wheels_;
    std::array<Door, 4> doors_;
};

int main() {
    Car car;
    car.openDoor();
    car.startEngine();
    car.turnWheel();
}