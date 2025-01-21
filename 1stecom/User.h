#pragma once
#include<iostream>
#include <string>

using namespace std;


class User {
protected:
	string username;
	string password;
	bool isLoggedIn;
	string role;
public:

	User(string username="username_null", string password= "password_null", bool log=false);
	User(const User &theUser);
	void setStatus(bool isLoggedIn);
	void setPassword(string password);
	void setUsername(string username);
	string getUsername();
	string getPassword();
	bool getStatus();
	string getRole();
	virtual void printUser()const = 0;

};
