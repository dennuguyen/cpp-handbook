#include <cmath>
#include <iostream>

class Math {
   public:
    static double sqrt(double val) { return std::sqrt(val); }
    static constexpr double pi = 3.14;
};

int main() {
    std::cout << Math::sqrt(3) << std::endl;  // Can use scope operator.
    std::cout << Math::pi << std::endl;       // Can use scope operator.

    Math math;
    std::cout << math.pi << std::endl;  // Can also instantiate and access with dot operator.
}