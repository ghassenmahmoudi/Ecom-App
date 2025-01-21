#include "Payment.h"
#include <ctype.h>

bool Payment::processPayment()
{
    if (!isValidCreditCard(CCNumber))
    {
        cout << "Invalid credit card number. Please enter a valid 16-digit number." << endl;
        return false;
    }
    
    if (!isValidExpirationDate(ExpDate))
    {
        cout << "Invalid expiration date. Please enter a valid date in the format MM/YY." << endl;
        return false;
    }

    if (!isValidCvv(cvv)) 
    {
        cout << "Invalid CVV. Please enter a valid 3-digit number." << endl;
        return false;
    }

    cout << "Payment processed successfully with credit card number: " << CCNumber << endl;
    return true;
}

void Payment::setCreditCardNumber(const string CCNumber)
{
    this->CCNumber = CCNumber;
}

void Payment::setExpirationDate(const string ExpDate)
{
    this->ExpDate = ExpDate;
}

void Payment::setCVV(const string cvv)
{
    this->cvv=cvv;
}

bool Payment::isValidCreditCard(const string creditCardNum)
{
    if (creditCardNum.length() != 16) {
        return false;
    }
    for (char c : creditCardNum) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool Payment::isValidExpirationDate(const string expDate)
{
    if (expDate.length() != 5 || expDate[2] != '/') {
        return false;
    }
    for (int i = 0; i < 5; ++i) {
        if (i != 2 && !isdigit(expDate[i])) {
            return false;
        }
    }
    string month = expDate.substr(0,2);
    int m = stoi(month);

    if (m < 1 || m > 12) {
        return false;
    }
    return true;

}

bool Payment::isValidCvv(const string cvv)
{
    if (cvv.length() != 3)
    {
        return false;
    }
    for (int i = 0; i < cvv.size(); i++)
    {
        if (!isdigit(cvv[i])) 
        {
            return false;
        }
    }
    return true;
}

string Payment::getCreditCard()
{
    return CCNumber;
}

string Payment::getExpdate()
{
    return ExpDate;
}





