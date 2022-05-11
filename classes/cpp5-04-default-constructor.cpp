#include <iostream>

class Person {
   public:
    Person(std::string const& name) : name_(name) {}

   private:
    std::string name_;
};

class Dog {
   public:
    // No user-defined constructors.
   private:
    std::string name_;
};

int main() {
    // auto p = Person();  // Compiler error. No such constructor.
    auto p = Person("L");  // This is fine.
    auto d = Dog();        // This is fine too.
}