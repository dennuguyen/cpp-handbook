#include <iostream>
#include <vector>

template <typename T, typename... Args>  // Variadic templates.
struct MyClass {
};

template <typename T, typename... Args>  // Variadic templates.
void print(T t, Args... args) {          // Pack expansion.
    std::cout << t << std::endl;
    print(args...);
}

void print() {}  // This is to stop recursion.

int main() {
    {
        auto m1 = MyClass<int, int, double, std::string>();       // Valid.
        auto m2 = MyClass<int, std::vector<int>, std::string>();  // Valid.
    }
    {
        print<double, int, std::string>(3.42, 4, "hello");
    }
}