#include <iostream>
#include <utility>

class Employee {
   public:
    Employee(std::string const& name, std::string const& company) : name_(name), company_(company) {
    }

    Employee& operator=(Employee&& other) noexcept {
        name_ = std::exchange(other.name_, "");
        company_ = std::exchange(other.company_, "");
        return *this;
    }

    std::string name_;
    std::string company_;
};

int main() {
    // auto employee1 = Employee("Matt", "OWR");  // Can't use this because copy assignment is implicitly deleted.
    Employee employee1("Matt", "OWR");
    Employee employee2("Matto", "OWR");

    // Pay close attention that employee2 is NOT newly-constructed.
    employee2 = std::move(employee1);  // Can only do this.

    std::cout << "1: " << employee1.name_ << employee1.company_ << std::endl;
    std::cout << "2: " << employee2.name_ << employee2.company_ << std::endl;
}