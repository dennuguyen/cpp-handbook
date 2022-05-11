#include <iostream>

class Person {
   public:
    Person(int const& id) : id_(id) {}
    Person(std::string const& name) : name_(name) {}

   private:
    int id_;
    std::string name_;
};

class Dog {
   public:
    explicit Dog(int const& id) : id_(id) {}
    explicit Dog(std::string const& name) : name_(name) {}

   private:
    int id_;
    std::string name_;
};

int main() {
    // Person 1 and 2 are legal type conversions.
    Person person1 = 1;
    Person person2 = std::string("Bob");

    // Since constructors are explicit, these will not compile.
    // Dog dog1 = 1;
    // Dog dog2 = "Doggo";

    // Better yet, use auto to discourage implicit type conversions.
    auto person3 = 1;                // Not a Person.
    auto person4 = Person("Bobby");  // Definitely a Person.
}