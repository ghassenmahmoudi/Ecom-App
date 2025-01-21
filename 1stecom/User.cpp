#include"User.h"



User::User(string username, string password, bool log)
{
	this->username = username;
	this->password = password;
	this->isLoggedIn = false;
}

User::User(const User& theUser)
{
	username = theUser.username;
	password = theUser.password;
	isLoggedIn = theUser.isLoggedIn;
	role = theUser.role;
}

void User::setStatus(bool isLoggedIn)
{
	this->isLoggedIn = isLoggedIn;
}

void User::setPassword(string password)
{
	this->password = password;
}

void User::setUsername(string username)
{
	this->username = username;
}

string User::getUsername()
{
	return username;
}

string User::getPassword()
{
	return password;
}

bool User::getStatus()
{
	return isLoggedIn;
}

string User::getRole()
{
	return role;
}
