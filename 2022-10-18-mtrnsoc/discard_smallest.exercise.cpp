// Your bag can only carry n integers at most. Once your bag has reached its capacity, the smallest
// value in the bag is replaced with the incoming num if it is larger.

#include <iostream>
#include <vector>

// Helper function to print vector.
auto print = [](std::vector<int> v) {
    for (auto const& i : v) std::cout << i << " ";
    std::cout << std::endl;
};

int main() {
    std::vector<int> bag;
    int cap;
    std::cin >> cap;
    int num;
    while (std::cin >> num) {
        // WRITE YOUR SOLUTION HERE.
        print(bag);
    }
}