#include <iostream>
int main() {
    int tokenType = 2;
    float tokenValue = 0.0f;
    switch (tokenType) {
        case 1: {
            int offset = 10;
            tokenValue = 50.0f + offset;
            break;
        }
        case 2: {
            int multiplier = 5;
            tokenValue = 20.0f * multiplier;
            break;
        }
        case 3: {
            tokenValue += 100.0f;
            break;
        }
        case 4: {
            std::cout << "Float token detected" << '\n';
            break;
        }
        default: {
            std::cout << "Unknown token" << '\n';
            break;
        }
    }
    std::cout << "Calculated Value: " << tokenValue << '\n';
    return 0;
}
