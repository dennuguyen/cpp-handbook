#include <iostream>
#include <vector>

class IntegerVector {
   public:
    IntegerVector(std::initializer_list<int> const& il) : data_(il) {}

   private:
    std::vector<int> data_;
};

int main() {
    auto intVec1 = IntegerVector({});          // With ({}) braces.
    auto intVec2 = IntegerVector{1, 2, 3};     // With just {} braces.
    IntegerVector intVec3 = {1, 2, 3, 5, 91};  // Without auto.
}