#include <iostream>

template <typename U, typename V>  // Primary template.
struct MyClass {};

template <typename U>     // Partial template specialisation.
struct MyClass<U, int> {  // V will always be int.
    int val = 24;
};

template <typename U, typename V>  // Partial template specialisation.
struct MyClass<U*, V> {            // U* is a pointer to U.

    int val = 52;
};
int main() {
    {
        MyClass<int, double> m1;
    }
    {
        MyClass<double, int> m2;
        std::cout << m2.val << std::endl;
    }
    {
        MyClass<int*, double> m3;
        std::cout << m3.val << std::endl;
    }
}