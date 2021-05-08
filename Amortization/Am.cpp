#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double yir;
double mir;
double balance;
//
//void print_chart(int P, double payment, double mir, int period_months){
//    double time = period_months;
//    double mir_n = mir;
//
//    double remain_Balance;
//
//    for(int i = 0; i < Y*12; i++){
//        interest_Paid = compute_interest_paid(mir, P);
//        total_Principle = compute_Total_Paid(payment, Y);
//        on_Principle = compute_Towards_Principle(payment, interest_Paid);
//        cout << i << setw(5) << payment << setw(5) << total_Principle << setw(5) << interest_Paid << setw(5) << remain_Balance << endl;
//
//    }
//}

double compute_payment(double LoanAmount, double mir, double period_months) {
    double a,b,c,d,e,f;
    double mir_n = mir;
    double payment;
//    cout << "mir: " << mir << endl; echo check
    a = 1 + mir_n;
    b = 1 / a;
    c = period_months;
    d = pow(b,c);
    e = 1 - d;
    f = LoanAmount * mir_n;
    payment = f/e;
    return payment;
}


//double compute_balance(double payment) {}

int main() {
//    double yir = 0; echo check
//    double mir = 0; echo check
    int period_years = 0;
    double LoanAmount = 0;
    double payment = 0;
    double amount_Paid = 0;
    
    cout << "Enter Principle" << endl;
    cin >> LoanAmount;
    
    cout << "Enter Yir: " << endl;
    cin >> yir;
    
    cout << "Enter Duration of Loan (Years): " << endl;
    cin >> period_years;
    
    int period_months = period_years * 12;
    mir = (yir) / 1200;

    
    cout << "LoanAmount: $" << setprecision(3) << fixed << LoanAmount << endl;
    cout << "Yir: " << setprecision(3) << yir << endl;
    cout << "mir: " << setprecision(3) << mir << endl;
    cout << "number months: " << setprecision(3) << period_months << endl;
    
    payment = compute_payment(LoanAmount,mir,period_months);
    
    cout << "Monthly Payment: $" << setprecision(3) << payment << endl;
    
    amount_Paid = payment * period_months;
    
    cout << "Total Interest Paid: $" << (amount_Paid - LoanAmount) << endl;
    cout << "Amount Paid: " << amount_Paid << endl;
    
    double interest_charge;
    double startingBalance = LoanAmount;
    double endingBalance = LoanAmount;
    cout << setw(6) << "Month: " << setw(6) << "Payment: " << setw(6) << "Interest Charge: " << setw(6) << "Ending Balance: " << endl;
    
    
    for(int i = 1; i <= period_months; i++)
    {
       interest_charge =  mir*startingBalance;
        endingBalance = startingBalance+interest_charge - payment;
        startingBalance = endingBalance;

        cout << setw(6) << i << setw(6) << setprecision(3) <<payment << setw(6) <<  setprecision(3)  << interest_charge << setw(6) <<  setprecision(3) << endingBalance;
    }
    return 0;
}
