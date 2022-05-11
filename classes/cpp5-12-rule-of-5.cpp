// Putting it all together.

#include <iostream>
#include <utility>

class Employee {
   public:
    Employee(std::string const& name, std::string const& company) : name_(name), company_(company) {
    }

    // Destructor.
    ~Employee() = default;

    // Move constructor.
    Employee(Employee&& other) noexcept
        : name_(std::exchange(other.name_, "")), company_(std::exchange(other.company_, "")) {
    }

    // Move assignment.
    Employee& operator=(Employee&& other) noexcept {
        name_ = std::exchange(other.name_, "");
        company_ = std::exchange(other.company_, "");
        return *this;
    }

    // Copy constructor.
    Employee(Employee const& other) : name_(other.name_), company_(other.company_) {}

    // Copy assignment.
    Employee& operator=(Employee const& other) {
        return Employee(other).swap(*this);
    }

   private:
    Employee& swap(Employee& other) {
        std::swap(name_, other.name_);
        std::swap(company_, other.company_);
        return *this;
    }

   public:
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