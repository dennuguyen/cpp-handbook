#include <iostream>

struct Base {
    Base() { std::cout << "Base Constructor\n"; }
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

struct Derived : public Base {
    Derived() { std::cout << "Derived Constructor\n"; }
    ~Derived() { std::cout << "Derived Destructor\n"; }
};

int main() {
    Base* base = new Derived();
    delete base;  // Derived destructor is never called!
}