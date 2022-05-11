#include <iostream>

bool isEven(int const a) { return a % 2 == 0; }

int multiply(int const a, int const b) { return a * b; }

int multiplyIfBothEven(int const a, int const b) {
    if (isEven(a) && isEven(b)) return multiply(a, b);
    return -1;
}

int main() {
    int a = 2;
    int b = 3;
    int c = 4;

    {
        std::cout << multiplyIfBothEven(a, b) << std::endl;
        std::cout << multiplyIfBothEven(a, c) << std::endl;
    }

    {
        int result = 0;
        if (a % 2 == 0 && b % 2 == 0) {
            result = a * b;
        } else {
            result = -1;
        }
        std::cout << result << std::endl;

        if (a % 2 == 0 && c % 2 == 0) {
            result = a * c;
        } else {
            result = -1;
        }
        std::cout << result << std::endl;
    }
}