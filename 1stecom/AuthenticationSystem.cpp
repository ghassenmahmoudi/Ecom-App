#include "AuthenticationSystem.h"
#include <functional>

using namespace std;



unordered_map<string, Customer>AuthenticationSystem:: LoggedInUsers;
CredentialDataBase AuthenticationSystem::Database;



AuthenticationSystem::AuthenticationSystem()
{
	Admin admin;
	Database.AddCredentials(admin.getUsername(),admin.getPassword());
	Database.addRole(admin.getUsername(), "Admin");
}

void AuthenticationSystem::signup(Customer& user)
{
	if (Database.CredentialExists(user.getUsername()))
	{
		cout << "You are already REGISTRED!" << endl;
	}
	else
	{
		Database.AddCredentials(user.getUsername(), user.getPassword());
		Database.addRole(user.getUsername(), user.getRole());
		cout << user.getRole() << " " << user.getUsername() << " Added." << endl;

			Admin::addCustomer(user);
		

	}
}

Customer AuthenticationSystem::login(string username, string password)
{
	Admin admin;


	if (Database.CredentialExists(username))
	{
		

		if (Database.GetPassword(username) == password)
		{
			if (LoggedInUsers.find(username) != LoggedInUsers.end())
			{
				throw 3;
			}
			if (Database.GetRole(username) == "Customer")
			{
				
				Customer user(username,password);
				user.setRole();
				user.setPassword(password);
				user.setStatus(true);
				LoggedInUsers.insert({username,user });
				cout << "Login Successful." << endl;
				return user;
			}
			else
			{
				cout << "You are The Admin" << endl;
				Customer user1 =admin;
				user1.setStatus(true);
				LoggedInUsers.insert({ username,user1 });
				return user1;
			}
		}

		else
		{	
			throw 1;
		}
	}
	else
	{
		throw 2;
	}
	
}

void AuthenticationSystem::changePassword(string username, string oldpass, string newpass)
{
	Customer user("nullname","nullpassword");
	for (auto& entry : AuthenticationSystem::Database.getCredentials())
	{
		if (username == entry.first)
		{
			user.setUsername(username);
			user.setPassword(entry.second);
		}
	}
	if (user.getPassword() == oldpass)
	{
		user.setPassword(newpass);
		Database.updatePassword(username, newpass);
		cout << "Password changed successfully." << endl;
	}
	else
	{
		cout << "Wrong Password" << endl;
	}
}

void AuthenticationSystem::changePasswordWithBackupPin(string username, string pin, string newpass)
{
	Customer user(username,"nullpassword");
	for (auto& entry : LoggedInUsers)
	{
		if (username == entry.first)
		{
			string pass = entry.second.getPassword();
			user.setPassword(pass);
			
		}
	}

	user.setPassword(newpass);
	Database.updatePassword(username, newpass);
	cout << "Password changed successfully using backup PIN.";

	
}

void AuthenticationSystem::logout(string username)
{
	bool flag = true;
	for (auto it = LoggedInUsers.begin(); it != LoggedInUsers.end(); ++it)
	{
		if (it->first == username)
		{
			flag = false;
			LoggedInUsers.erase(it);
			cout << "Logout Successfully!" << endl;
			break;
		}
	}
	if (flag==true)
	{
		throw 1;
	}
	
	
}
