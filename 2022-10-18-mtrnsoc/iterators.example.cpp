#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec(0);
    *vec.begin() = 42;        // Base address.
    *(vec.begin() + 1) = 43;  // Offsets by sizeof(int) * 1.
    *(vec.begin() + 2) = 44;  // Offsets by sizeof(int) * 2.
    std::cout << *vec.begin() << std::endl;
    std::cout << *(vec.begin() + 1) << std::endl;
    std::cout << *(vec.begin() + 2) << std::endl;
}