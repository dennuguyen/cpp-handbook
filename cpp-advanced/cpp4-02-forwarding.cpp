#include <iostream>

void inner(int& val) {
    std::cout << "lvalue inner called" << std::endl;
}

void inner(int&& val) {
    std::cout << "rvalue inner called" << std::endl;
}

void outer(int&& val) {
    inner(val);
}

void outer_fixed(int&& val) {
    inner(std::forward<int>(val));
}

int main() {
    outer(20);  // Problem. Rvalue gets modified into Lvalue. We never wanted this to become a variable.
    outer_fixed(20);
}