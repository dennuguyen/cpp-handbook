#include <iostream>

struct Base {
    virtual int getValue() { return 16; }
};

struct Derived : public Base {
    int getValue() override { return 42; }
};

int main() {
    Base base;
    std::cout << base.getValue() << std::endl;

    Derived derived;
    std::cout << derived.getValue() << std::endl;
}