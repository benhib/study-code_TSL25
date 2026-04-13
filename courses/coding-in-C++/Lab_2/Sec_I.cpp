#include <iostream>
#include <string>

class BankAccount {
    private:
        std::string owner;
        double balance;

    public:
        void setOwner(std::string owner) {
            this->owner = owner;
        };

        std::string getOwner() {
            return owner;
        };

        void deposit(double deposit) {
            if (deposit <= 0) {
                std::cout << "Deposits can't be less than 0$\n";
                return;
            }

            this->balance += deposit;
            std::cout << "You've deposited " << deposit << "$ in your account\n";
        };

        void withdraw(double withdrawl) {
            if (withdrawl <= 0) {
                std::cout << "Withdrawls can't be less than 0$\n";
                return;
            }

            if(this->balance < withdrawl) {
                std::cout << "You don't have enough money in your account\n";
                return;
            }

            this->balance -= withdrawl;
            std::cout << "You've withdrawn " << withdrawl << "$ from your account\n";
        };

        double getBalance();

        void getAccountInfo();

};

double BankAccount::getBalance() {
        return this->balance;
    }

    void BankAccount::getAccountInfo() {
        std::cout << "Owner: " << this->owner << "\n";
        std::cout << "Balance: " << this->balance << "$\n";
    }

int main() {
    BankAccount test_account;

    test_account.setOwner("Ben Hibinger");

    std::cout << "Created with Owner: " << test_account.getOwner() << "\n";

    test_account.deposit(-1.0);

    test_account.deposit(1000.5);

    std::cout << "New balance: " << test_account.getBalance() << "\n";

    test_account.withdraw(20000);

    test_account.withdraw(-1);

    test_account.withdraw(251.2);

    test_account.getAccountInfo();

}