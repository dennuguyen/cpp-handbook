// https://en.cppreference.com/w/cpp/language/typeid

#include <iostream>
#include <typeinfo>

int main() {
    int x = 0;
    double y = 2.2;
    char z = 'a';

    // Numeric conversion.
    {
        int myInt = z;  // What value is myInt?
        std::cout << myInt << std::endl;
    }

    // Numeric promotion.
    {
        std::cout << typeid(z).name() << std::endl;

        auto intOrChar = x + z;  // What data type is intOrChar?
        std::cout << typeid(intOrChar).name() << std::endl;

        auto sum = x + y + z;  // What data type is sum?
        std::cout << typeid(sum).name() << std::endl;
    }

    return 0;
}
