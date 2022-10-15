#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> s;
    s.insert("abc");
    s.insert("abc");
    s.erase("abc");
}