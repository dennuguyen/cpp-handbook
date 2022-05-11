#include <iostream>

auto main() -> int {
    int *ptr1 = new int;
    int *ptr2 = new int;

    *ptr1 = 42;
    ptr2 = ptr1;  // ptr1 and ptr2 both have the same address.

    {
        std::cout << *ptr1 << std::endl;
        std::cout << *ptr2 << std::endl;
    }

    delete ptr1;

    {
        std::cout << *ptr2 << std::endl;  // What does this print?
    }

    delete ptr2;  // What happens here?

    return 0;
}