#include <iostream>

int main() {
    int* ptr{new int[3]};
    *ptr = 42;        // Base address.
    *(ptr + 1) = 43;  // Offsets by sizeof(int) * 1.
    *(ptr + 2) = 44;  // Offsets by sizeof(int) * 2.
    std::cout << *ptr << std::endl;
    std::cout << *(ptr + 1) << std::endl;
    std::cout << *(ptr + 2) << std::endl;
}