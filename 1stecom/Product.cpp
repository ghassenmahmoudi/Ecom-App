#include "Product.h"
#include <iostream>


using namespace std;
Product::Product()
{
	name = "";
	brand = "";
	quantity = 0;
	price = 0;
	id = "";
	category = Category::EMPTY;
	state = StockState::OUT_OF_STOCK;
}

Product::Product(const Product& TheProduct)
{
	this->name = TheProduct.name;
	this->brand = TheProduct.brand;
	this->quantity = TheProduct.quantity;
	this->price = TheProduct.price;
	this->id = TheProduct.id;
	this->category = TheProduct.category;
	this->state = TheProduct.state;

}

Product::Product(string brand, string name, double price, int quantity)
{
	this->name = name;
	this->brand = brand;
	this->quantity = quantity;
	this->price = price;
	category = Category::EMPTY;
	state = StockState::OUT_OF_STOCK;
}

void Product::setid(string id)
{
	this->id = id;
}

void Product::setbrand(string brand)
{
	this->brand = brand;
}

void Product::setname(string name)
{
	this->name = name;
}

void Product::setprice(double price)
{
	this->price = price;
}

void Product::setcategrory(Category categrory)
{
	this->category = category;
}

void Product::setquantity(int quantity)
{
	this->quantity = quantity;
}

string Product::getid()
{
	return string(id);
}

string Product::getbrand()
{
	return string(brand);
}

string Product::getname()
{
	return string(name);
}

Category Product::getcategory()
{
	return category;
}



double Product::getprice()
{
	return price;
}

int Product::getquantity()
{
	return quantity;
}

void Product::decreasequantity(int q)
{
	if (q > 0)
	{
		quantity = max(0, quantity - q);
	}
}

void Product::updateProduct()
{
	string newName;
	cout << "Enter new Product name (or press 'skip' to keep the current name): " << endl;
	cin >> newName;
	if (newName.compare("skip")!=0)
	{
		setname(newName);
	}
	cout << "Enter new Product brand (or press 'skip' to keep the current brand): " << endl;
	string newBrand;
	cin >> newBrand;
	if (newBrand.compare("skip") != 0)
	{
		setbrand(newBrand);
	}
	cout << "Enter new Product price (or press -1 to keep the current price): " << endl;
	double newPrice;
	cin >> newPrice;
	if (newPrice!=-1)
	{
		setprice(newPrice);
	}
	cout << "Enter new Product quantity (or press -1 to keep the current quantity): " << endl;
	int newQuantity;
	cin >> newQuantity;
	if (newQuantity != -1)
	{
		setquantity(newQuantity);
	}



}

void Product::updateStockState()
{
	if (quantity > 5) {
		state = StockState::IN_STOCK;
	}
	else if (quantity > 0 && quantity <= 5) {
		state = StockState::LOW_STOCK;
	}
	else
	{
		state = StockState::OUT_OF_STOCK;
	}
}

void Product::setState(StockState state)
{
		this->state = state;
}

void Product::displayProductDetails() const
{
	cout << "-----------------------------------------------" << endl;
}

bool Product::operator==(const Product& other) const
{
	return (id == other.id );
}

bool Product::operator!=(const Product& other) const
{
	return (id != other.id || brand != other.brand || name != other.name);
}

Product Product::operator=(const Product& TheProduct) const
{
	Product product(TheProduct);
	return product;
}


