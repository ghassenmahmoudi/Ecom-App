#include "Customer.h"

Customer::Customer()
{
	role = "Customer";
	cout << "Set your username :" << endl;
	string forInput;
	cin >> forInput;
	username = forInput;
	cout << "Set your password :" << endl;
	cin >> forInput;
	password = forInput;
	isLoggedIn = false;
	

}

Customer::Customer(string username, string password)
{
	this->username = username;
	this->password = password;
}

Customer::Customer(const Customer& theUser)
{
	this->username = theUser.username;
	this->password = theUser.password;
	this->role = theUser.role;
	this->backup_pin = theUser.backup_pin;
	this->isLoggedIn = theUser.isLoggedIn;
	this->cart = theUser.cart;

}

void Customer::setBackUpPin()
{
	int i;
	do {
		cout << "Set your back_up pin (4 numbers allowed!):" << endl;
		cin >> i;
		if (i <= 9999 && i>=1000)
		{
			backup_pin = to_string(i);
		}
		else
		{
			cout << "Your Input should be a numeric and no more than 4 digits , try again please !!!" << endl;

		}
	} while (i > 9999 || i<1000);
}

string Customer::getBackUpPin()
{
	return backup_pin;
}



void Customer::setRole(string s)
{
	this->role = s;
}





Cart Customer::getCart()
{
	return cart;
}

void Customer::viewCart()
{
	cart.showCart();
}

void Customer::addProduct()
{
	cout << "Enter the product's Id : ";
	string id;
	cin >> id;
	cout << "Enter the quantity : ";
	int quantity;
	cin >> quantity;
	cart.addItem(id, quantity);
}

void Customer::removeProduct()
{
	cout << "Enter the product's Id : ";
	string id;
	cin >> id;
	cart.removeItem(id);
}

void Customer::confirmProduct()
{
	cout << "Enter the product ID to confirm: "<<endl;
	string id;
	cin >> id;
	if (cart.containsItem(id))
	{
		Product product ( Inventory::SearchProductByID(id));
		if (product.getquantity() >= cart.showQuantity(id))
		{
			cout << "Order confirmed successfully!" << endl;
			product.decreasequantity(cart.showQuantity(id));
			cart.removeItem(id);

		}
		else {
			cout << "Sorry! Insufficiant Quantity :(" << endl;
		}
	}
	else {
		cout << "Product not found" << endl;
	}
}

void Customer::printUser() const
{
	cout << "Name : " << username << endl;
	cout << "Password : " << password << endl;
	cout << "backup Pin : " << backup_pin << endl;
}



