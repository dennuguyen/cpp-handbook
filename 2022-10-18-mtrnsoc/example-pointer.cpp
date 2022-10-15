#include <iostream>

int main() {
    int var1{42};
    int var2{43};
    int* ptr{&var1};
    std::cout << ptr << std::endl;
    std::cout << ptr + 1 << std::endl;
}