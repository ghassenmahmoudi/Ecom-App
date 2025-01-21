#pragma once
#include <iostream>
#include <unordered_map> 
#include <fstream> 
#include <string> 
#include <sstream>

using namespace std;


class CredentialDataBase {
private:
	unordered_map<string, string> credentials;
	unordered_map<string, string> roles;
	string CredentialsFile;
	string RoleFile;
public:

	CredentialDataBase(); 
	CredentialDataBase(const string& CredentialsFile, const string& RoleFile);
	void readingFromFile(unordered_map<string, string> &zdata, const string& Thefile);
	void writingToFile(unordered_map<string, string>& zdata, const string& Thefile);
	void AddCredentials(const string& username, const string& password);
	void addRole(const string& username, const string& role);
	void updatePassword(const string& username, const string& NewPass);
	bool CredentialExists(const string& username);
	bool CustomerExists(const string& username);
	string GetRole(const string& username);
	string GetPassword(const string& username);
	unordered_map<string, string> getRoles();
	unordered_map<string, string> getCredentials();
	void initializeDataFromFile();

};