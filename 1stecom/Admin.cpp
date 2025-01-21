#include "Admin.h"
#include"Inventory.h"
#include "AuthenticationSystem.h"




vector < Customer > Admin::customers;

Admin::Admin()
{
	username = "admin";
	password = "admin";
	role = "Admin";
}


bool Admin::existCustomer(string username)
{
	for (Customer customer : customers)
	{
		if ((username.compare(customer.getUsername())) == 0)
		{
			return true;
		}
	}
	return false;

}

void Admin::addCustomer(Customer &customer)
{
	if (!existCustomer(customer.getUsername()))
	{
		customers.push_back(customer);
	}
}

Customer Admin::getCustomer_Username(string username)
{
	for (Customer customer : customers)
	{
		if ((username.compare(customer.getUsername())) == 0)
		{
			return customer;
		}
	}
	throw 1;  //Customer does not Exist!
}

void Admin::addProduct_Inventory()
{
	Inventory::addProduct();
}

void Admin::change_ProductQuantity()
{
	cout << "Enter Product ID: ";
	string id;
	cin >> id;
	try {
		Product theProduct = Inventory::SearchProductByID(id);
		cout << "Enter The New Quantity: "<<endl;
		int quantity;
		cin >> quantity;
		Inventory::changeProductQuantity(id, quantity);
		cout << "Product quantity updated successfully!" << endl;
	}
	catch (int e)
	{
		cout << "Product not found." << endl;
	}

}

void Admin::UpdateProduct()
{
	cout << "Enter product ID: " << endl;
	string id;
	cin >> id;
	try{
	Inventory::updateProduct(id);
	}

	catch (int e)
	{
		cout << "Product Not Found" << endl;
	}
}

void Admin::removeProduct_Inventory()
{
	cout << "Enter product ID: " << endl;
	string id;
	cin >> id;
	try {
		Product product = Inventory::SearchProductByID(id);
		Inventory::deleteProduct(product);
		cout << "Product removed from inventory successfully!" << endl;
	}
	catch (int e)
	{
			cout<<"Product Not Found" << endl;
	}


}

void Admin::displayCustomers()
{
	unordered_map<string, string> Thecustomers = AuthenticationSystem::Database.getRoles();
	if (Thecustomers.empty())
	{
		cout << "There is No Customer Available!" << endl;

	}
	else {
		for (auto TheCustomer : Thecustomers)
		{
			if (TheCustomer.second.compare("Customer") == 0)
			{
				cout << "Username: " << TheCustomer.first << endl;
			}
		}
	}
	
}

void Admin::printUser() const
{
	cout << "Name : " << username << endl;
	cout << "Password : " << password << endl;
}

Admin::operator Customer()
{
	Customer customer(username, password);
	customer.setRole("Admin");
	return customer;
}




