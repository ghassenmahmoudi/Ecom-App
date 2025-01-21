#pragma once
#include<iostream>
#include "User.h"
#include "Admin.h"
#include "AuthenticationSystem.h"
#include "Customer.h"
#include "Order.h"
#include "Payment.h"
#include "Transaction.h"



using namespace std;


void TheMenu()
{
    cout << "===========================\n";
    cout << "1. Login\n";
    cout << "2. Sign Up\n";
    cout << "3. Change Password\n";
    cout << "4. User Operations\n";
    cout << "5. Logout\n";
    cout << "6. Exit\n";
    cout << "===========================\n";
    cout << "Enter your choice: \n" << endl;
}
Customer login()
{
    string user, pass;
    Customer customer("nulluser", "nullpass");
    cout << "Enter Username: \n";
    cin >> user;
    cout << "Enter Password: \n";
    cin >> pass;
    try {
        Customer custom = AuthenticationSystem::login(user, pass);
        return custom;
    }
    catch (int e)
    {
        switch (e)
        {
        case 1:
            cout << "Invalid credentials." << endl;
            return customer;
            break;
        case 2:
            cout << "You are not registered, please Sign up First!" << endl;
            return customer;
            break;
        case 3:
            cout << "You are already connected." << endl;
            customer.setUsername(user);
            customer.setPassword(pass);
            customer.setStatus(true);
            customer.setRole();
            return  customer;
            break;
        default:
            cout << "Error" << endl;
            return customer;
            break;
        }
    }
    TheMenu();
}
void signup()
{
    Customer customer;
    AuthenticationSystem::signup(customer);  

}

void ChangePassword()
{
    string user, OLDpass,NEWpass;
    cout << "Enter Username: \n";
    cin >> user;
    cout << "Enter Old Password: \n";
    cin >> OLDpass;
    cout << "Enter New Password: " << endl;
    cin >> NEWpass;
    AuthenticationSystem::changePassword(user, OLDpass, NEWpass);

}

void ChangePasswordWithPIN(Customer customer)
{
    string user, NEWpass;
    string Bpin;
    cout << "Enter Username: \n";
    cin >> user;
    cout << "Enter Backup PIN: \n";
    cin >> Bpin;
    cout << "Enter New Password: " << endl;
    cin >> NEWpass;
    if (customer.getBackUpPin()==Bpin)
        AuthenticationSystem::changePasswordWithBackupPin(user, Bpin, NEWpass);
    else
        cout << "Password change failed" << endl;

}

void CheckPayment(Payment payment)
{
    string creditCardNumber, expirationDate, cvv;
    while (true) {
        cout << "Enter your 16-digit credit card number: ";
        cin >> creditCardNumber;
        payment.setCreditCardNumber(creditCardNumber);

        cout << "Enter the expiration date (MM/YY): ";
        cin >> expirationDate;
        payment.setExpirationDate(expirationDate);

        cout << "Enter the CVV: ";
        cin >> cvv;
        payment.setCVV(cvv);

        if (payment.processPayment()) {
            Transaction::addPayment(creditCardNumber, expirationDate);
            break;
        }
    }
}

void AdminMenu()
{
    int choice;
  do
   {
       cout << "================================\n";
       cout << "Admin Menu:\n";
       cout << "1. Add Product to Inventory\n";
       cout << "2. Change Product Quantity in Inventory\n";
       cout << "3. Modify Product\n";
       cout << "4. Remove Product from Inventory\n";
       cout << "5. View Transactions\n";
       cout << "6. View Customers\n";
       cout << "7. Exit\n";
       cout << "================================\n";
       cin >> choice;
       if (cin.fail() || choice < 1 || choice > 7)
       {
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
           printf("Invalid choice.Please enter a valid option.\n");
       }
        switch (choice)
        {
        case 1:
            Admin::addProduct_Inventory();
            break;
        case 2:
            Inventory::displayAllProducts();
            Admin::change_ProductQuantity();

            break;
        case 3:
            Inventory::displayAllProducts();
            Admin::UpdateProduct();

            break;
        case 4:
            Inventory::displayAllProducts();
            Admin::removeProduct_Inventory();

            break;
        case 5:
            Transaction::printAllPayments();
            break;
        case 6:
            Admin::displayCustomers();

            break;
        case 7:
            cout << "Exiting Admin Menu. \n";
            return;
            break;
        default:
            
            break;
        }
   

  } while (choice != 7);

}



void CustomerMenu(Customer customer)
{
    Payment payment;
    int choice;
    do
    {
 
        cout << "===============================\n";
        cout << "Customer Menu:\n";
        cout << "1. View Products\n";
        cout << "2. Add Product\n";
        cout << "3. Remove Product\n";
        cout << "4. View Cart\n";
        cout << "5. Confirm Product\n";
        cout << "6. Filter Products By Category\n";
        cout << "7. Filter Products By Price Range\n";
        cout << "8. Search Product By Product Name\n";
        cout << "9. Set Back-Up Pin\n";
        cout << "10. Exit\n";
        cout << "===============================\n";

        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("Invalid choice.Please enter a valid option.\n");
        }
            switch (choice)
            {
            case 1:
                Inventory::displayAllProducts();
                break;
            case 2:
                customer.addProduct();
                break;
            case 3:
                customer.removeProduct();
                break;
            case 4:
                customer.viewCart();
                break;
            case 5:   
                customer.confirmProduct();
                CheckPayment(payment);
                break;
            case 6:
                Inventory::filterProductsByCategory();
                break;
            case 7:
                Inventory::filterProductsByPrice();
                break;
            case 8:
                Inventory::SearchProductByName();

                break;
            case 9:
                customer.setBackUpPin();
                break;
            case 10:
                cout << "GoodBye :)" << endl;
                return;
                break;
            default:

                break;
            }
            
    } while (choice != 10);
}

int main()
{

    
    AuthenticationSystem::AuthenticationSystem();
    Customer user("nullUser", "nullPassword");
    int choice;

    
    do
    {
        
        string UserToLogout;
        TheMenu();
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("Invalid choice.Please enter a valid option.\n");
        }
        switch (choice)
        {
        case 1:
           user = login();

            break;
        case 2:
            signup();

            break;
        case 3:
            
            cout << "Choose password change method : \n";
            cout << "1- Change Password \n";
            cout << "2- Change Password with Backup PIN(Set up your Backup Pin before using it)\n " ;
            cout << "3- Exit" << endl;
            int select;
            
            do
            {
                cin >> select;
                if (cin.fail() || select < 1 || select > 3)
            {
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     printf("Invalid choice.Please enter a valid option.\n");
            }   
            switch (select)
            {
            case 1:
                ChangePassword();
                
                break;
            case 2:
                ChangePasswordWithPIN(user);
                
                break;
            case 3:
                break;
            default:
               
                break;
            }
            } while (select != 3);

            break;
        case 4:
            if (user.getStatus())
            {
                if (user.getRole() == "Admin")
                {
                    AdminMenu();
               

                }
                else if (user.getRole() == "Customer")
                {
                   CustomerMenu(user);
                  
                }
            }
                else
                {
                    cout << "Login is Required!" << endl;
          
                }

            break;
        case 5:
            cout << "Enter Your Username: ";
            cin >> UserToLogout;
            try {

                AuthenticationSystem::logout(UserToLogout);
            }
            catch (int e) {
                cout << "You are not Logged in!" << endl;
            }
      
            break;
        case 6:
            cout << "Thank you for choosing Us. Goodbye!" << endl;
            exit(0);
            break;
        default:

            break;
        }

    } while (choice != 6);
    
	return 0;
}
