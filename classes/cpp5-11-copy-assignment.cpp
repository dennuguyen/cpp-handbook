#include <iostream>
#include <utility>

class Employee {
   public:
    Employee(std::string const& name, std::string const& company) : name_(name), company_(company) {
    }

    Employee& operator=(Employee const& other) {
        return Employee(other).swap(*this);
    }

    std::string name_;
    std::string company_;

   private:
    Employee& swap(Employee& other) {
        std::swap(name_, other.name_);
        std::swap(company_, other.company_);
        return *this;
    }
};

int main() {
    auto employee1 = Employee("Matt", "OWR");
    auto employee2 = Employee("Matto", "OWR");

    // Pay close attention that employee2 is NOT newly-constructed.
    employee2 = employee1;

    std::cout << "1: " << employee1.name_ << employee1.company_ << std::endl;
    std::cout << "2: " << employee2.name_ << employee2.company_ << std::endl;
}