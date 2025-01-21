#include "furnitureProduct.h"


int furnitureProduct::autoINC = 0;
furnitureProduct::furnitureProduct()
{
	type = furnitureType::EMPTY;
	category = Category::FURNITURE;
	id = "F-" + to_string(autoINC);
	autoINC++;
	int c;
	bool validChoice = false;
	cout << "Enter furniture Type: Table,Chair,Desk... \n";
	cout << "1-TABLE\n";
	cout << "2-CHAIR\n";
	cout << "3-DESK\n";
	cout << "4-BED\n";
	cout << "5-MATTRESS\n";
	cout << "6-SOFA\n";
	cout << "7-FRIDGE\n";
	cout << "8-DISHWASHER\n";
	cout << "9- EXIT\n";
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
			type = furnitureType::TABLE;
			validChoice = true;
			break;
		case 2:
			type = furnitureType::CHAIR;
			validChoice = true;
			break;
		case 3:
			type = furnitureType::DESK;
			validChoice = true;
			break;
		case 4:
			type = furnitureType::BED;
			validChoice = true;
			break;
		case 5:
			type = furnitureType::MATTRESS;
			validChoice = true;
			break;
		case 6:
			type = furnitureType::SOFA;
			validChoice = true;
			break;
		case 7:
			type = furnitureType::FRIDGE;
			validChoice = true;
			break;
		case 8:
			type = furnitureType::DISHWASHER;
			validChoice = true;
			break;
		default:
			cout << "Invalid Choice" << endl;
			break;
		}
	} while (!validChoice);
	cout << "Enter Product dimensions: \n" ;
	cin >> dimentions;
	cout << "Enter product material: \n" ;
	cin >> material;
	cout << "Enter Name: \n";
	cin >> name;
	cout << "Enter Brand: \n";
	cin >> brand;
	setbrand( brand);
	cout << "Enter price: \n";
	cin >> price;
	setprice(price);
	cout << "Enter Quantity: " << endl;
	cin >> quantity;
	setquantity(quantity);
	updateStockState();

}

furnitureProduct::furnitureProduct(string brand, string name, double price, int quantity, furnitureType type, string dimensions, string material)
{
	Product(brand, name, price, quantity);
	this->dimentions = dimensions;
	this->material = material;
	this->type = type;
	category = Category::FURNITURE;
	id = "F-" + to_string(autoINC);
	autoINC++;
	
}

furnitureType furnitureProduct::getType()
{
	return type;
}

string furnitureProduct::getMaterial()
{
	return material;
}

string furnitureProduct::getDimentions()
{
	return dimentions;
}

void furnitureProduct::setMaterial(string material)
{
	this->material = material;
}

void furnitureProduct::setDimentions(string dimentions)
{
	this->dimentions = dimentions;
}

void furnitureProduct::displayProductDetails()const
{
	cout << "Product ID: " << id<<endl;
	switch (type) {
	case furnitureType::TABLE:
		cout << "Type: TABLE" << endl;
		break;
	case furnitureType::CHAIR:
		cout << "Type: CHAIR" << endl;
		break;
	case furnitureType::DESK:
		cout << "Type: DESK" << endl;
		break;
	case furnitureType::BED:
		cout << "Type: BED" << endl;
		break;
	case furnitureType::MATTRESS:
		cout << "Type: MATTRESS" << endl;
		break;
	case furnitureType::SOFA:
		cout << "Type: SOFA" << endl;
		break;
	case furnitureType::FRIDGE:
		cout << "Type: FRIDGE" << endl;
		break;
	case furnitureType::DISHWASHER:
		cout << "Type: DISHWASHER" << endl;
		break;
	default:
		break;
	}

	cout << "Brand: " << brand<<"\n";
	cout << "Name: " << name << "\n";
	cout << "Dimentions: " << dimentions << "\n";
	cout << "Material: " << material << "\n";
	cout << "Price: $" << price << "\n";
	cout << "Quantity: " << quantity << "\n";
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
