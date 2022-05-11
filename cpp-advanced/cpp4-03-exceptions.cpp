#include <cassert>
#include <iostream>
#include <vector>

int main() {
    try {
        // Don't actually try-catch this example IRL. This example is simple and NOT exceptional.
        const int a = 3;

        // One way to catch an exception.
        if (a != 4) {
            throw std::logic_error("Expected " + std::to_string(a) + " to be 4.");
        }

        // Another way to catch an exception is if code somewhere in the function throws.
        std::vector<int> vec;
        vec.at(2);

    } catch (std::logic_error const& e) {
        std::cerr << "Logic Error: " << e.what() << std::endl;

    } catch (std::exception const& e) {  // Catches a particular exception object.
        std::cerr << "Exception Error: " << e.what() << std::endl;
        throw;  // Rethrow so code somewhere higher up can catch it.

    } catch (...) {  // Catches any exception.
        std::cerr << "Catch all." << std::endl;
    }
}