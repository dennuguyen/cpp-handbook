#include <iostream>

int main() {
    int marks = 90;

    {
        if (marks > 50) {
            std::cout << "Your grade is pass (PS)" << std::endl;
        } else if (marks > 65) {
            std::cout << "Your grade is credit (CR)" << std::endl;
        } else if (marks > 75) {
            std::cout << "Your grade is distinction (DN)" << std::endl;
        } else if (marks > 85) {
            std::cout << "Your grade is high distinction (HD)" << std::endl;
        } else {
            std::cout << "Your grade is fail (FL)" << std::endl;
        }
    }

    // {
    //     if (marks > 50) {
    //         std::cout << "Your grade is pass (PS)" << std::endl;
    //     }
    //     if (marks > 65) {
    //         std::cout << "Your grade is credit (CR)" << std::endl;
    //     }
    //     if (marks > 75) {
    //         std::cout << "Your grade is distinction (DN)" << std::endl;
    //     }
    //     if (marks > 85) {
    //         std::cout << "Your grade is high distinction (HD)" << std::endl;
    //     } else {
    //         std::cout << "Your grade is fail (FL)" << std::endl;
    //     }
    // }

    // {
    //     if (marks >= 85) {
    //         std::cout << "Your grade is high distinction (HD)" << std::endl;
    //     } else if (marks >= 75) {
    //         std::cout << "Your grade is distinction (DN)" << std::endl;
    //     } else if (marks >= 65) {
    //         std::cout << "Your grade is credit (CR)" << std::endl;
    //     } else if (marks >= 50) {
    //         std::cout << "Your grade is pass (PS)" << std::endl;
    //     } else {
    //         std::cout << "Your grade is fail (FL)" << std::endl;
    //     }
    // }

    // {
    //     int x = 5;
    //     switch (x) {
    //         case 1:
    //         case 2:
    //         case 3:
    //             std::cout << "Choice is either 1, 2, 3" << std::endl;
    //             break;
    //         case 4:
    //             std::cout << "Choice is 4" << std::endl;
    //             break;
    //         default:
    //             std::cout << "Others" << std::endl;
    //             break;
    //     }
    // }

    return 0;
}
