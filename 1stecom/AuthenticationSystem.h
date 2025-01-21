#pragma once
#include <iostream>
#include "User.h"
#include "Admin.h"
#include "CredentialDataBase.h"
#include <unordered_map>

using namespace std;

class AuthenticationSystem {
private:
	static CredentialDataBase Database;
	static unordered_map<string, Customer> LoggedInUsers;
public:
	friend class Admin;			// used in void Admin::displayCustomers()
	AuthenticationSystem();
	static void signup(Customer& user);
	static Customer login(string username, string password);
	static void changePassword(string username, string oldpass, string newpass);
	static void changePasswordWithBackupPin(string username, string pin, string newpass);
	static void logout(string username);
};