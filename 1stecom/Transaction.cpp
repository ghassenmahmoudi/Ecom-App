#include "Transaction.h"


unordered_map<string, string> Transaction::payments;

void Transaction::addPayment( string CreditCardNum,  string ExpDate) {

    payments[CreditCardNum] = ExpDate;
}

void Transaction::printAllPayments()  {
    if (payments.empty()) {
        cout << "No payments found." << endl; 
    }
    else {
        for (auto& entry : payments)
        {
            cout << "Credit Card Number: " << entry.first.substr(0,4)<<"************" << endl;
            cout << "Expiration Date: " << entry.second << endl;
            cout << "--------------------------" << endl;
        }
    }
}