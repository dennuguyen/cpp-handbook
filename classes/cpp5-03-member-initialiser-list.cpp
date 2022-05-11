#include <iostream>

class Employee {
   public:
    Employee(std::string const& name, std::string& company) : name_(name), company_(company) {
        // name_ = name;        // Compiler error because const variables cannot be reassigned.
        // company_ = company;  // Compiler error because references cannot be assigned upon initialisation.
    }

   private:
    std::string const name_;
    std::string& company_;
};

int main() {
}