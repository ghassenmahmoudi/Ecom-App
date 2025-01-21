#pragma once
#include "User.h"
#include <vector>
#include "Customer.h"
#include "Inventory.h"
#include "CredentialDataBase.h"

class Customer;
using namespace std;

class Admin : public User
{private:
	static vector < Customer > customers;
public:
	Admin();
	static bool existCustomer(string username);
	static void addCustomer(Customer &customer);
    static Customer getCustomer_Username(string username);
	static void addProduct_Inventory();
	static void change_ProductQuantity();
	static void UpdateProduct();
	static void removeProduct_Inventory();
	static void displayCustomers();
	void printUser()const;
	operator Customer();


};