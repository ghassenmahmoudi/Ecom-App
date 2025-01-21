#pragma once
#include "User.h"
#include "Cart.h"
#include "Admin.h"

using namespace std;

class Customer : public User
{
private:
	string backup_pin;
	double balance = 0;
	Cart cart;
public:
	Customer();
	Customer(string username, string password);
	Customer(const Customer& theUser);
	void setBackUpPin();
	string getBackUpPin();
	void setRole(string s="Customer");
	Cart getCart();
	void viewCart();
	void addProduct();
	void removeProduct();
	void confirmProduct();
	void printUser()const;

};