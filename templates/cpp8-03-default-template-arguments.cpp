#include <array>
#include <iostream>

template <typename T = std::string, std::size_t size = 42>
struct array {
    std::array<T, size> data;
    T type_;
    int size_ = size;
};

constexpr int a = 303;

int main() {
    array<int, 10> arr1;
    array<int> arr2;
    array<> arr3;

    std::cout << typeid(arr1.type_).name() << " " << arr1.size_ << std::endl;
    std::cout << typeid(arr2.type_).name() << " " << arr2.size_ << std::endl;
    std::cout << typeid(arr3.type_).name() << " " << arr3.size_ << std::endl;
}