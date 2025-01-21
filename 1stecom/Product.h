#pragma once
#include<iostream>
#include <string>
#include "Category.h"
#include "StockState.h"

using namespace std;


class Product
{
protected:
	string id;
	string brand;
	string name;
	double price;
	StockState state;
	Category category;
	int quantity;
public:
	friend class Cart  ;
	Product();
	Product(const Product &TheProduct);
	Product(string brand, string name, double price, int quantity);
	void setid(string id);
	void setbrand(string brand);
	void setname(string name);
	void setprice(double price);
	void setcategrory(Category categrory);
	void setquantity(int quantity);
	string getid();
	string getbrand();
	string getname();
	Category getcategory();
	double getprice();
	int getquantity();
	void decreasequantity(int q);
	void updateProduct();
	void updateStockState();
	void setState(StockState state);
	virtual void displayProductDetails()const;
	bool operator==(const Product& other) const;
	bool operator !=(const Product& other) const;
	Product operator =(const Product& TheProduct) const;
	// Define hash function for Product
	struct ProductHash {
		size_t operator()(const Product& p) const {
			// Hash the product ID
			return hash<string>{}(p.id);
		}
	};


	



	


};