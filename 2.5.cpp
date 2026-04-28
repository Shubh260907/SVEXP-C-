#include <iostream>
#include <string>

using namespace std;

class LoanAccount {
private:
    int loanID;
    string applicantName;
    double principal;
    double annualRate;
    int tenureMonths;

    double power(double base, int exp) const {
        double result = 1.0;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

public:
    LoanAccount() {
        loanID = 0;
        applicantName = "New Applicant";
        principal = 0.0;
        annualRate = 0.0;
        tenureMonths = 1;
    }

    LoanAccount(int id, string name, double p, double rate, int t) {
        loanID = id;
        applicantName = name;
        principal = (p > 0) ? p : 0;
        annualRate = (rate > 0) ? rate : 0;
        tenureMonths = (t > 0) ? t : 1;
    }

    double calculateEMI() const {
        if (principal <= 0 || annualRate <= 0 || tenureMonths <= 0) return 0;

        double r = annualRate / 1200.0;
        int t = tenureMonths;

        double commonTerm = power(1 + r, t);

        double emi = (principal * r * commonTerm) / (commonTerm - 1);
        return emi;
    }

    void display() const {
        cout << "ID: " << loanID << " | Name: " << applicantName << endl;
        cout << "Principal: " << principal << " | Rate: " << annualRate << "%" << endl;
        cout << "Tenure: " << tenureMonths << " months" << endl;
        cout << "Monthly EMI: " << calculateEMI() << endl;
        cout << "------------------------------------------" << endl;
    }
};

int main() {

    LoanAccount loan1(7001, "Alice Smith", 10000, 12.0, 12);

    cout << "Loan Details and EMI Calculation" << endl;
    cout << "------------------------------------------" << endl;
    loan1.display();

    return 0;
}
