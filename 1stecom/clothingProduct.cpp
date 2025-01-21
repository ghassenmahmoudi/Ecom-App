#include "clothingProduct.h"

int clothingProduct::autoINC = 0;

clothingProduct::clothingProduct()
{
	category = Category::CLOTHING;
	id = "C-" + to_string(autoINC);
	autoINC++;
	int c;
	bool validChoice = false;
	do {
		cout << "Enter clothing Type: SHIRT,SWEATER,PANTS... \n";
		cout << "1-SHIRT\n";
		cout << "2-SWEATER\n";
		cout << "3-PANTS\n";
		cout << "4-SHORTS\n";
		cout << "5-JEANS\n";
		cout << "6-DRESS\n";
		cout << "7-EYEGLASSES\n";
		cout << "8-JACKET\n";
		cout << "9- EXIT" << endl;
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
			type = clothingType::SHIRT;
			validChoice = true;
			break;
		case 2:
			type = clothingType::SWEATER;
			validChoice = true;
			break;
		case 3:
			type = clothingType::PANTS;
			validChoice = true;
			break;
		case 4:
			type = clothingType::SHORTS;
			validChoice = true;
			break;
		case 5:
			type = clothingType::JEANS;
			validChoice = true;
			break;
		case 6:
			type = clothingType::DRESS;
			validChoice = true;
			break;
		case 7:
			type = clothingType::EYEGLASSES;
			validChoice = true;
			break;
		case 8:
			type = clothingType::JACKET;
			validChoice = true;
			break;
		default:
			cout << "Invalid Choice\n" << endl;
			break;
		}
	} while (!validChoice);
	cout << "Enter Product Size: " << endl;
	cin >> size;
	cout << "Enter product Material: " << endl;
	cin >> material;
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

clothingProduct::clothingProduct(string brand, string name, double price, int quantity, clothingType type, string size, string material)
{
	Product(brand, name, price, quantity);
	this->type = type;
	this->size = size;
	this->material = material;
	category = Category::CLOTHING;
	id = "C-" + to_string(autoINC);

}

clothingType clothingProduct::getType()
{
	return type;
}

string clothingProduct::getSize()
{
	return size;
}

string clothingProduct::getMaterial()
{
	return material;
}

void clothingProduct::setSize(string size)
{
	this->size = size;
}

void clothingProduct::setMaterial(string Material)
{
	this->material = material;
}

void clothingProduct::displayProductDetails() const
{
	cout << "Product ID: " << id<<endl;
	switch (type) {
	case clothingType::SHIRT:
		cout << "Type: SHIRT" << endl;
		break;
	case clothingType::SWEATER:
		cout << "Type: SWEATER" << endl;
		break;
	case clothingType::PANTS:
		cout << "Type: PANTS" << endl;
		break;
	case clothingType::SHORTS:
		cout << "Type: SHORTS" << endl;
		break;
	case clothingType::JEANS:
		cout << "Type: JEANS" << endl;
		break;
	case clothingType::DRESS:
		cout << "Type: DRESS" << endl;
		break;
	case clothingType::EYEGLASSES:
		cout << "Type: EYEGLASSES" << endl;
		break;
	case clothingType::JACKET:
		cout << "Type: JACKET" << endl;
		break;
	default:
		break;
	}

	cout << "Brand: " << brand << "\n";
	cout << "Name: " << name << "\n";
	cout << "Size: " << size << "\n";
	cout << "Material: " << material << "\n";
	cout << "Price: $" << price << "\n";
	cout << "Quantity: " << quantity<< "\n";
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
