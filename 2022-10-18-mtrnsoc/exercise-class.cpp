#include <iostream>
#include <vector>

class Vector {
public:
    // Default constructor.
    Vector();

    // User-defined constructor using initialiser list.
    Vector(int size);
    Vector(std::vector<int> vec);

    // Copy constructor.
    Vector(Vector const& other);

    // Move constructor.
    Vector(Vector&& other);

    // Copy assignment.
    Vector& operator=(Vector const& other);

    // Move assignment.
    Vector& operator=(Vector&& other);

private:
    std::vector<int> data_;
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