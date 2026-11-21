#include <iostream>
const double globalTaxRate = 0.18;
int main() {
    const double itemPrice = 1000.0;
    const double localTaxRate = 0.05;
    std::cout << "Local Rate: " << localTaxRate << '\n';
    const double totalWithGlobalTax = itemPrice * (1.0 + ::globalTaxRate);
    {
        const int corporateTaxPercent = 12;
        (void)corporateTaxPercent;
        const double totalWithLocalTax = itemPrice * (1.0 + localTaxRate);
        std::cout << "Inner total: " << totalWithLocalTax << '\n';
    }
    std::cout << "Final Global Calculation: " << totalWithGlobalTax << '\n';
    return 0;
}
