#include <cmath>
#include <iostream>
class MathVector {
public:
    double x, y;
    MathVector(double a, double b) : x(a), y(b) {}
    bool operator==(const MathVector& other) const { return x == other.x && y == other.y; }
    MathVector operator+(const MathVector& other) const { return {x + other.x, y + other.y}; }
    MathVector powComponents(int power) const { return {std::pow(x, power), std::pow(y, power)}; }
};
int main() {
    MathVector v1(2.0, 3.0), v2(2.0, 3.0);
    MathVector sum = v1 + v2;
    MathVector sq = v1.powComponents(2);
    std::cout << std::boolalpha << "Equal: " << (v1 == v2) << '\n';
    std::cout << "Sum: (" << sum.x << ", " << sum.y << ")\n";
    std::cout << "Componentwise power 2: (" << sq.x << ", " << sq.y << ")\n";
}
