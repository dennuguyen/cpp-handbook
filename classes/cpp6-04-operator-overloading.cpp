#include <iostream>
#include <vector>

class Number {
   public:
    Number() = default;
    Number(double data) : data_(data) {}

    Number operator+() const {
        return *this;
    }

    Number operator-() const {
        Number retval;
        retval.data_ = -retval.data_;
        return retval;
    }

    friend Number operator+(Number const& lhs, Number const& rhs) {
        Number retval;
        retval.data_ = lhs.data_ + rhs.data_;
        return retval;
    }

    friend Number operator-(Number const& lhs, Number const& rhs) {
        Number retval;
        retval.data_ = lhs.data_ - rhs.data_;
        return retval;
    }

    friend Number operator*(Number const& lhs, Number const& rhs) {
        Number retval;
        retval.data_ = lhs.data_ * rhs.data_;
        return retval;
    }

    friend Number operator/(Number const& lhs, Number const& rhs) {
        Number retval;
        try {
            retval.data_ = lhs.data_ / rhs.data_;
        } catch (std::logic_error e) {
            std::cerr << e.what() << std::endl;
        }
        return retval;
    }

    friend std::ostream& operator<<(std::ostream& os, Number const& num) {
        os << num.data_;
        return os;
    }

    // Overload type conversions.
    operator int() { return data_ * 10; }  // If for some reason we want to double it.
    operator double() { return data_ * 10; }
    operator double*() {
        double* retval = new double;
        *retval = data_;
        return retval;
    }

   private:
    double data_;
};

int main() {
    Number n1 = 2;
    Number n2 = 24;
    Number n3 = 0;
    Number n4 = -1;

    std::cout << n4 << std::endl;
    std::cout << (n1 * n2) << std::endl;
    std::cout << (n3 / n4) << std::endl;
    std::cout << static_cast<double>(n1) << std::endl;
}