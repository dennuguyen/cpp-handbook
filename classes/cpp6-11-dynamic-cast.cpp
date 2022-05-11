#include <cassert>
#include <iostream>
#include <stdexcept>

struct Base {
    virtual ~Base() = default;
};

struct Derived : Base {};

int main() {
    {  // Up-casting.
        Derived derived;
        Base& b1 = dynamic_cast<Base&>(derived);   // Up-casting a reference
        Base* b2 = dynamic_cast<Base*>(&derived);  // Up-casting a pointer.
    }
    {  // Down-casting a pointer.
        Base* base = new Derived;
        Derived* derived = dynamic_cast<Derived*>(base);  // Down-casting a pointer.
        if (derived != nullptr) {
            std::cout << "Down-casted." << std::endl;
        }
        delete base;
    }
    {  // Down-casting a reference.
        Derived d1;
        Base& base = d1;                                  // Implict up-cast.
        Derived& derived = dynamic_cast<Derived&>(base);  // Down-casting a reference.
        std::cout << "Down-casted." << std::endl;
    }
    {  // Cannot dynamic cast because Base was defined initially as Base.
        Base* base = new Base;
        Derived* derived = dynamic_cast<Derived*>(base);  // Down-casting a pointer.
        if (derived == nullptr) {                         // A reference will throw std::bad_cast.
            std::cout << "Derived is always a nullptr" << std::endl;
        }
        delete base;
    }
}