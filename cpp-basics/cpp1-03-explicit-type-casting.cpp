#include <iomanip>
#include <iostream>

int main() {
    std::cout << std::fixed << std::setprecision(1);  // 1 d.p.

    // The following are all conversions from double to int.
    {
        double a = 2.2;
        int b = a;                    // implicit conversion.
        int c = (int)(a);             // explicit C-style type cast.
        int d = static_cast<int>(a);  // explicit C++ style type cast.
        std::cout << b << " " << c << " " << d << std::endl;
    }

    // Type casting fractions.
    {
        int x = 2;
        int y = 5;
        auto result1 = static_cast<double>(y / x);  // int / int
        auto result2 =
            static_cast<double>(y) / static_cast<double>(x);  // double / double
        std::cout << result1 << " " << result2 << std::endl;
    }

    // std::cout << x << y << a << std::endl;
}