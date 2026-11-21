#include <iostream>
int main() {
    int a = 25;
    int &refA = a;
    const int &refLiteral = 100;
    double pi = 3.14159;
    const double &refPi = pi;
    const int &constRef = 50;
    int updatedValue = constRef + 10;
    std::cout << a << " " << refA << '\n';
    std::cout << "Literal: " << refLiteral << '\n';
    std::cout << "Pi: " << refPi << '\n';
    std::cout << "Updated value: " << updatedValue << '\n';
    return 0;
}
