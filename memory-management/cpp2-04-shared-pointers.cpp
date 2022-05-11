#include <iostream>
#include <memory>

auto main() -> int {
    auto sharedPtr1 = std::make_shared<std::string>("I'm shared ");
    auto sharedPtr2 = std::shared_ptr<std::string>(sharedPtr1);

    {
        std::cout << *sharedPtr1 << std::endl;
        std::cout << *sharedPtr2 << std::endl;
    }

    sharedPtr2->append("with everyone!\n");

    {
        std::cout << *sharedPtr1 << std::endl;
        std::cout << *sharedPtr2 << std::endl;
    }

    return 0;
}