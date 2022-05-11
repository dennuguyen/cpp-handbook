#include <iostream>

class Employee {
   public:
    // Construct using an initialiser list.
    Employee(std::string name, std::string company) : name_(name), company_(company) {
    }

    // Construct by assignment.
    Employee(std::string name, std::string company) {
        name_ = name;
        company_ = company;
    }

    // Construct with just name.
    Employee(std::string name) {
        name_ = name;
    }

   private:
    std::string name_;
    std::string company_;
};

int main() {
    Employee employee1("Bob", "OWR");   // One way to instantiate.
    auto employee2 = Employee("Jill");  // Another way to instantiate.
}