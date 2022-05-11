#include <cassert>
#include <iostream>
#include <stdexcept>

struct Base {
    virtual ~Base() = default;
    virtual std::string out() { return "Base"; }
};

struct Derived : Base {
    std::string out() override { return "Derived"; }
};

int main() {
    Base* b1 = new Base;
    Base* b2 = new Derived;  // Implicit up-cast.

    // What will these print?
    std::cout << b1->out() << std::endl;
    std::cout << b2->out() << std::endl;

    // Overriding behaviour is preserved so to print Base's out().
    std::cout << b1->Base::out() << std::endl;
    std::cout << b2->Base::out() << std::endl;
}