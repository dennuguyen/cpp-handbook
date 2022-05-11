#include <array>
#include <cmath>
#include <iostream>

class Robot {
   public:
    // Nested class.
    class Wheel {
       public:  // Must be public or is inaccessible in Robot.
        void moveForward() {
            pose_++;
        }

        void debug() {
            std::cout << pose_ << std::endl;
        }

       private:
        int pose_ = 0;
    };

    // Nested enum.
    enum Data {
        NUM_WHEELS = 2,
        NUM_SENSORS = 8,
    };

    void moveForward() {
        for (auto& wheel : wheels_) {
            wheel.moveForward();
        }
    }

    void debug() {
        for (auto& wheel : wheels_) {
            wheel.debug();
        }
    }

   private:
    std::array<Wheel, NUM_WHEELS> wheels_;
};

int main() {
    Robot robot;
    robot.debug();
    robot.moveForward();
    robot.debug();
}