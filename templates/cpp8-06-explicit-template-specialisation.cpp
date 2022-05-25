#include <iostream>

template <typename T>
struct MyClass {
    T val;
};

template <>
struct MyClass<int> {
    int val = 30;
};

int main() {
    {
        MyClass<double> m1;
        std::cout << m1.val << std::endl;
    }
    {
        MyClass<int> m2;
        std::cout << m2.val << std::endl;
    }
}