#include <iostream>

template <std::size_t size, const int& t>
struct MyClass {
    std::size_t size_ = size;
    int something_ = t;
};

constexpr int a = 303;

int main() {
    MyClass<42, a> m;
    std::cout << "My class size is: " << m.size_ << std::endl;
    std::cout << "My something is: " << m.something_ << std::endl;  // Better style to just use non-type template parameters for sizing.
}