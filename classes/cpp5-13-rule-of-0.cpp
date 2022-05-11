// Putting it all together but big brain.

#include <iostream>
#include <utility>

class Employee {
   public:
    Employee(std::string const& name, std::string const& company) : name_(name), company_(company) {
    }

    std::string name_;
    std::string company_;
};

int main() {
    auto employee1 = Employee("Matt", "OWR");
    auto employee2 = Employee("Matto", "OWR");
    auto employee3 = employee2;

    employee2 = std::move(employee1);

    std::cout << "1: " << employee1.name_ << employee1.company_ << std::endl;
    std::cout << "2: " << employee2.name_ << employee2.company_ << std::endl;
    std::cout << "3: " << employee3.name_ << employee3.company_ << std::endl;
}