#include <iostream>

class Vector {
public:
    // Default constructor.
    Vector() { std::cout << "Default constructor called." << std::endl; }

    // User-defined constructor using initialiser list.
    Vector(int size) : size_(size) { std::cout << "User-defined constructor called." << std::endl; }

    // User-defined constructor using assignment.
    // Vector(int size) {
    //     std::cout << "User-defined constructor called." << std::endl;
    //     size_ = size;
    // }

    // Copy constructor.
    Vector(Vector const& other) : size_(other.size_) {
        std::cout << "Copy constructor called." << std::endl;
    }

    // Move constructor.
    Vector(Vector&& other) : size_(std::exchange(other.size_, 0)) {
        std::cout << "Move constructor called." << std::endl;
    }

    // Copy assignment.
    Vector& operator=(Vector const& other) {
        std::cout << "Copy assignment called." << std::endl;
        size_ = other.size_;
        return *this;
    }

    // Move assignment.
    Vector& operator=(Vector&& other) {
        std::cout << "Move assignment called." << std::endl;
        size_ = std::exchange(other.size_, 0);
        return *this;
    }

private:
    int size_;
};

int main() {
    Vector v1;                 // Uses default constructor.
    Vector v2(3);              // Uses our user-defined constructor.
    Vector v3(v2);             // Uses copy constructor.
    Vector v4(std::move(v3));  // Uses move constructor.
    Vector v5;                 // Uses default constructor.
    v5 = v2;                   // Uses copy assignment.
    Vector v6;                 // Uses default constructor.
    v6 = std::move(v5);        // Uses move assignment.
}