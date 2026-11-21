#include <iostream>
#include <string>
#include <utility>

class BankingException {
    std::string msg;
public:
    explicit BankingException(std::string m) : msg(std::move(m)) {}
    virtual ~BankingException() = default;
    virtual const std::string& getMessage() const { return msg; }
};

class InsufficientFundsException : public BankingException {
    double shortfall;
public:
    InsufficientFundsException(std::string m, double sf)
        : BankingException(std::move(m)), shortfall(sf) {}
    double getShortfall() const { return shortfall; }
};

void processWithdrawal(double balance, double amount) {
    if (amount > balance)
        throw InsufficientFundsException("Account overdrawn!", amount - balance);
}

int main() {
    try {
        processWithdrawal(500.0, 750.0);
    } catch (const InsufficientFundsException& ife) {
        std::cout << "Shortfall of: $" << ife.getShortfall() << '\n';
    } catch (const BankingException& be) {
        std::cout << "General Banking Error: " << be.getMessage() << '\n';
    } catch (...) {
        std::cout << "Unexpected error.\n";
    }
}
