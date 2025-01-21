#pragma once
#include <iostream>
#include "Payment.h"
#include <unordered_map>

class Transaction {
private:
    static unordered_map<string,string> payments;

public:
    static void addPayment( string CreditCardNum,  string ExpDate);
    static void printAllPayments() ;
};

