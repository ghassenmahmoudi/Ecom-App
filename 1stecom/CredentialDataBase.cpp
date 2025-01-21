#include "CredentialDataBase.h"




void CredentialDataBase::readingFromFile(unordered_map<string, string>& zdata, const string& Thefile) {
    ifstream file(Thefile);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string key, value;
            getline(ss, key, '=');
            getline(ss, value);
            if (!key.empty() && !value.empty()) {
                zdata[key] = value;
            }
        }
        file.close();
    }
    else {
        cout << "Error With The File" << endl;
    }
}


void CredentialDataBase::writingToFile(unordered_map<string, string>& zdata, const string& Thefile)
{
    ofstream file(Thefile);
    if (file.is_open())
    {
        for (const auto& entry : zdata)
        {
            file << entry.first << "=" << entry.second << endl;
        }
        file.close();
    }
    else
    {
        cout << "Error With The File" << endl;
    }
}


CredentialDataBase::CredentialDataBase() {
    CredentialsFile = "credentials.txt";
    RoleFile = "roles.txt";
    initializeDataFromFile();
}

CredentialDataBase::CredentialDataBase(const string& CredentialsFile, const string& RoleFile) {
    this->CredentialsFile = CredentialsFile;
    this->RoleFile = RoleFile;
    initializeDataFromFile();
}

void CredentialDataBase::initializeDataFromFile() {
    ifstream dataIn(CredentialsFile);
    ifstream dataIn2(RoleFile);

    if (!dataIn.fail() && !dataIn2.fail()) {
        readingFromFile(credentials, CredentialsFile);
        readingFromFile(roles, RoleFile);
    }
    else {
        cout << "One or more files do not exist or cannot be opened." << endl;
    }
}

void CredentialDataBase::AddCredentials(const string& username, const string& password) {
    credentials[username] = password;
    writingToFile(credentials, CredentialsFile);
}

void CredentialDataBase::addRole(const string& username, const string& role) {
    roles[username] = role;
    writingToFile(roles, RoleFile);
}

void CredentialDataBase::updatePassword(const string& username, const string& NewPass) {
    credentials[username] = NewPass;
    writingToFile(credentials, CredentialsFile);
}

bool CredentialDataBase::CredentialExists(const string& username) {
    return (credentials.count(username) > 0);
}

bool CredentialDataBase::CustomerExists(const string& username) {
    string customer = "Customer";
    string tofind = roles[username];
    return CredentialExists(username) && (customer.compare(tofind) == 0);
}

string CredentialDataBase::GetRole(const string& username) {
    return roles[username];
}

string CredentialDataBase::GetPassword(const string& username) {
    return credentials[username];
}

unordered_map<string, string> CredentialDataBase::getRoles() {
    return roles;
}

unordered_map<string, string> CredentialDataBase::getCredentials() {
    return credentials;
}


