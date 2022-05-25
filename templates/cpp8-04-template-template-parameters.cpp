#include <array>
#include <iostream>

template <typename T>
struct container {
    T value_;
};

template <template <typename> typename U, typename V>
struct array {
    U<V> type_;
};

constexpr int a = 303;

int main() {
    array<container, int> arr1;
    arr1.type_.value_ = 30.4;
    std::cout << arr1.type_.value_ << std::endl;
}