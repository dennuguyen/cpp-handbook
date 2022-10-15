#include <iostream>
#include <map>
#include <string>

int main() {
    std::string str("abbccc");
    std::map<char, int> count;
    count['a'] = 1;  // Access via 'a' to assign 1.
    count['b'];      // Inserts a key 'b'.

    for (auto const& entry : count) {
        std::cout << entry.first << std::endl;   // Key.
        std::cout << entry.second << std::endl;  // Value.
    }
}