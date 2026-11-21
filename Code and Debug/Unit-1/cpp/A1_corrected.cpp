#include <iostream>
int main() {
    unsigned char num = 15;
    if (((num & 1u) == 1u) && num > 10) {
        std::cout << "Valid Odd Number: " << static_cast<int>(num) << '\n';
    } else {
        std::cout << "Condition Failed for: " << static_cast<int>(num) << '\n';
    }
    for (int i = 3; i >= 0; --i) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    return 0;
}
