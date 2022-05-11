#include <iostream>

int main() {
    std::string str1 = "this is ";
    std::string str2 = "my string";
    if (str1 != str2) {
        std::cout << str1 + str2 << std::endl;
    }

    return 0;
}