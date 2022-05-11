#include <iostream>

auto main() -> int {
    int orig = 21;
    int& ref = orig;  // Reference to orig

    // References must be initialised.
    {
        int& ref;  // Won't compile.
    }

    // References cannot be re-referenced.
    {
        int other = 99;
        ref = other;  // Can only re-assign value.
        std::cout << ref << std::endl;
    }

    // References cannot be assigned NULL.
    {
        int& ref = NULL;  // Won't compile.
    }

    // What does ref print?
    {
        orig = 36;
        std::cout << ref << std::endl;
        std::cout << orig << std::endl;
    }

    // What does orig print?
    {
        ref = 42;
        std::cout << ref << std::endl;
        std::cout << orig << std::endl;
    }

    // Address?
    {
        std::cout << &ref << std::endl;
        std::cout << &orig << std::endl;
    }

    return 0;
}