#include <iostream>

class Employee {
   public:
    Employee(std::string const& name, std::string const& company) : name_(name), company_(company) {
    }

    Employee(Employee const& other) : name_(other.name_), company_(other.company_) {}

    std::string name_;
    std::string company_;
};

int main() {
    auto employee1 = Employee("Matt", "OWR");

    // Pay close attention that employee2 and employee3 are newly-constructed.
    auto employee2 = Employee(employee1);  // Can do this.
    auto employee3 = employee1;            // Or this.

    std::cout << "1: " << employee1.name_ << employee1.company_ << std::endl;
    std::cout << "2: " << employee2.name_ << employee2.company_ << std::endl;
    std::cout << "3: " << employee3.name_ << employee3.company_ << std::endl;
}