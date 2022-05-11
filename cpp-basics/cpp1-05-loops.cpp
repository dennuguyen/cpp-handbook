#include <iostream>

void countingWhileLoop() {
    int i = 0;
    while (i < 10) {
        std::cout << i << std::endl;
        i++;
    }
}

void infiniteWhileLoop() {
    int i = 0;

    bool stayInLoop = true;
    while (stayInLoop) {
        std::cout << i << std::endl;
        if (i == 10) {  // break condition
            stayInLoop = false;
        }
        i++;
    }
}

void countingForLoop() {
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }
}

int main() {
    countingWhileLoop();
    // infiniteWhileLoop();
    // countingForLoop();
}