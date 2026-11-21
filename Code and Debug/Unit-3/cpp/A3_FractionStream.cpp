#include <iostream>
#include <stdexcept>
class Fraction {
    int numerator;
    int denominator;
public:
    Fraction(int n, int d) : numerator(n), denominator(d) {
        if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    }
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        return os << f.numerator << '/' << f.denominator;
    }
};
int main() {
    Fraction f1(3, 4);
    std::cout << f1 << '\n';
}
