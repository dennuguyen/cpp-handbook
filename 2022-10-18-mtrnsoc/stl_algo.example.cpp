#include <algorithm>
#include <cctype>
#include <iostream>
#include <set>
#include <string>
#include <vector>

// Helper function to print vector.
auto print = [](std::vector<int> v) {
    for (auto const& i : v) std::cout << i << " ";
    std::cout << std::endl;
};

int main() {
    // Fill example.
    {
        std::vector<int> v(100);

        // Instead of this.
        for (auto& i : v) {
            i = 42;
        }

        // Do this.
        std::fill(v.begin(), v.end(), 42);

        print(v);
    }

    // Equal example.
    {
        std::vector<int> v{1, 2, 3};
        std::set<int> s{1, 2, 3};
        // std::cout << std::boolalpha << (v == s) << std::endl;  // Compiler error.
        std::cout << std::boolalpha << std::equal(v.begin(), v.end(), s.begin()) << std::endl;
    }

    // Transform example.
    {
        std::string str{"abcdefg"};
        std::transform(str.begin(), str.end(), str.begin(),
                       [](char const& c) { return std::toupper(c); });
        std::cout << str << std::endl;
    }
}