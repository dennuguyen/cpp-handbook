#include <iostream>
#include <map>

auto main() -> int {
    auto m = std::map<int, std::string>({
        {1, "hello"},
        {2, "world"},
    });

    {  // Accessing elements.
        std::cout << m.at(1) << std::endl;
        std::cout << m.find(2) << std::endl;
    }

    {  // Inserting elements.
        m[3] = "goodbye";
        // m.at(4) = "world";  // Error.
        // m.insert(3) = "good";  // Error.
        m.insert_or_assign(3) = "goodbye everyone";
    }

    return 0;
}