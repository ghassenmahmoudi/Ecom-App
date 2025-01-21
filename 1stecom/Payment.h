#pragma once
#include <string>
#include <iostream>
using namespace std;


class Payment {

    string CCNumber;
    string ExpDate;
    string cvv;
    
public:
    bool processPayment();
    void setCreditCardNumber(const string CCNumber);
    void setExpirationDate(const string ExpDate);
    void setCVV(const string cvv);
    bool isValidCreditCard(const string creditCardNum);
    bool isValidExpirationDate(const string expDate);
    bool isValidCvv(const string cvv);
    string getCreditCard();
    string getExpdate();
 };