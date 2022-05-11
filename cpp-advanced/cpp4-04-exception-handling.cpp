#include <cassert>
#include <iostream>
#include <vector>

bool triple(int& val) {
    val *= 3;
    return true;
}

int main() {
    int val = 3;

    try {  // No throw guarantee.
        if (triple(val)) {
            throw;
        }
    } catch (std::exception const& e) {
        // An exception is caught but we're not telling the user about it.
    }

    try {  // Basic exception safety.
        if (triple(val)) {
            throw;
        }
    } catch (std::exception const& e) {
        std::cerr << "Basic exception safety: " << val << std::endl;
    }

    try {  // Strong exception safety.
        int temp = val;
        if (triple(temp)) {
            throw;
        }
    } catch (std::exception const& e) {
        std::cerr << "Strong exception safety: " << val << std::endl;
    }
}