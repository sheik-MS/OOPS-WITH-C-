#include <iostream>
#include <string>
class BankAccount {
    std::string accHolder;
    double balance;
    static double totalBankReserves;
public:
    BankAccount(std::string name, double deposit)
        : accHolder(name), balance(deposit) { totalBankReserves += deposit; }
    void displayAccount() const {
        std::cout << "Account Holder: " << accHolder
                  << ", Balance: $" << balance << '\n';
    }
    static void displayAudit() {
        std::cout << "Total Reserves in Vault: $" << totalBankReserves << '\n';
    }
};
double BankAccount::totalBankReserves = 0.0;
int main() {
    BankAccount acc1("Alice", 5000.0), acc2("Bob", 3000.0);
    BankAccount::displayAudit();
    acc1.displayAccount();
    acc2.displayAccount();
}
