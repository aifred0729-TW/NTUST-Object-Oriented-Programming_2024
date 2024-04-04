
class BankAccount {
    private:
    int        balance;
    static int total;

    public:
    BankAccount() {
        balance = 0;
    }

    BankAccount(int input) {
        balance = input;
        total += balance;
    }

    void withdraw(int output) {
        balance -= output;
        total -= output;
    }

    void save(int input) {
        balance += input;
        total += input;
    }

    int getBalance() {
        return balance;
    }

    static int getAllMoneyInBank() {
        return total;
    }
};

int BankAccount::total = 0;