#include <iostream>

class Person {
   public:
    // Naive way.
    Person(int id) : id_(id) {}
    Person(std::string name) : name_(name) {}
    Person(int id, std::string name) : id_(id), name_(name) {}

    // Our most generalised constructor.
    Person(int id, std::string name, std::string address) : id_(id), name_(name), address_(address) {}

    // Using delegating constructors.
    Person(int id) : Person(id, "") {}                          // Delegate to line 16.
    Person(std::string name) : Person(0, name, "") {}           // Delegate to line 11.
    Person(int id, std::string name) : Person(id, name, "") {}  // Delegate to line 11.

   private:
    int id_;
    std::string name_;
    std::string address_;
};

int main() {
    auto p = Person("L");  // This is fine.
}