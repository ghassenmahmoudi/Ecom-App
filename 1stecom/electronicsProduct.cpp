#include "electronicsProduct.h"
#include <cctype>
#include <algorithm>


int electronicsProduct::autoINC = 0;
electronicsProduct::electronicsProduct(string brand, string name, double price, int quantity, electronicsType type, string model)
{
	Product(brand, name, price, quantity);
	this->type=type;
	this->model = model;
	category = Category::ELECTRONICS;
	id = "E-" + to_string(autoINC);



}


electronicsProduct::electronicsProduct()
{
	category = Category::ELECTRONICS;
	id = "E-" + to_string(autoINC);
	autoINC++;
	int c;
	bool validChoice = false;
	cout << "Enter Electronics Type: SMARTPHONE,LAPTOP,COMPUTER... \n";
	cout << "1-SMARTPHONE\n";
	cout << "2-LAPTOP\n";
	cout << "3-COMPUTER\n";
	cout << "4-TV\n";
	cout << "5-KEYBOARD\n";
	cout << "6-MOUSE\n";
	cout << "7-HEADPHONE\n";
	cout << "8-CHARGER\n";
	cout << "9- EXIT\n" << endl;
	do {

		cin >> c;
		if (cin.fail() || c < 1 || c > 9)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("Invalid choice.Please enter a valid option.\n");
		}
		switch (c)
		{
		case 1:
			type = electronicsType::SMARTPHONE;
			validChoice = true;
			break;
		case 2:
			type = electronicsType::LAPTOP;
			validChoice = true;
			break;
		case 3:
			type = electronicsType::COMPUTER;
			validChoice = true;
			break;
		case 4:
			type = electronicsType::TV;
			validChoice = true;
			break;
		case 5:
			type = electronicsType::KEYBOARD;
			validChoice = true;
			break;
		case 6:
			type = electronicsType::MOUSE;
			validChoice = true;
			break;
		case 7:
			type = electronicsType::HEADPHONE;
			validChoice = true;
			break;
		case 8:
			type = electronicsType::CHARGER;
			validChoice = true;
			break;
		default:
			
			break;
		}
	} while (!validChoice);
	cout << "Enter Product Model:\n";
	cin >> model;
	cout << "Enter Name: \n";
	cin >> name;
	cout << "Enter Brand: \n";
	cin >> brand;
	setbrand(brand);
	cout << "Enter price: \n";
	cin >> price;
	setprice(price);
	cout << "Enter Quantity: " << endl;
	cin >> quantity;
	setquantity(quantity);
	updateStockState();





}

electronicsType electronicsProduct::getType()
{
	return type;
}

string electronicsProduct::getModel()
{
	return model;
}

void electronicsProduct::setModel(string model)
{
	this->model = model;
}

void electronicsProduct::displayProductDetails()const
{
	cout<<"Product ID: " << id<<endl;
	switch (type) {
	case electronicsType::SMARTPHONE:
		cout << "Type: SMARTPHONE" << endl;
		break;
	case electronicsType::LAPTOP:
		cout << "Type: LAPTOP" << endl;
		break;
	case electronicsType::COMPUTER:
		cout << "Type: COMPUTER" << endl;
		break;
	case electronicsType::TV:
		cout << "Type: TV" << endl;
		break;
	case electronicsType::KEYBOARD:
		cout << "Type: KEYBOARD" << endl;
		break;
	case electronicsType::MOUSE:
		cout << "Type: MOUSE" << endl;
		break;
	case electronicsType::HEADPHONE:
		cout << "Type: HEADPHONE" << endl;
		break;
	case electronicsType::CHARGER:
		cout << "Type: CHARGER" << endl;
		break;
	default:
		break;
	}

	cout << "Brand: " << brand << "\n";
	cout<<"Name: " << name << "\n";
	cout<<"Model: " << model << "\n";
	cout<<"Price: $" << price << "\n";
	cout<<"Quantity: " << quantity << "\n";
	switch (state)
	{
	case StockState::IN_STOCK:
		cout << "Stock State: IN_STOCK" << endl;
		break;
	case StockState::LOW_STOCK:
		cout << "Stock State: LOW_STOCK" << endl;
		break;
	case StockState::COMING_SOON:
		cout << "Stock State: COMING_SOON" << endl;
		break;
	case StockState::OUT_OF_STOCK:
		cout << "Stock State: OUT_OF_STOCK" << endl;
		break;
	default:
		break;
		
	}
	cout << "----------------------------------" << endl;
	
}


