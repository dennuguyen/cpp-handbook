#include <iostream>

struct Base1 {
    int base1value = 3;
};
struct Base2 {
    int base2value = 5;
};
class Derived : public Base1, public Base2 {};

int main() {
    Derived d;
    std::cout << d.base1value << " " << d.base2value << std::endl;
}