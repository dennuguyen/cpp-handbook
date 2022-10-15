#include <iostream>

int main() {
    int var{42};
    int* ptr{&var};
    std::cout << ptr << std::endl;   // Prints the address.
    std::cout << *ptr << std::endl;  // Prints the value AT the address.}
}