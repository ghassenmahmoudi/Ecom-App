#pragma once
#include<iostream>
#include "Product.h"
#include "electronicsType.h"
using namespace std;

class electronicsProduct : public Product {
private:
	static int autoINC;
	electronicsType type;
	string model;
public:
	electronicsProduct(string brand, string name, double price, int quantity, electronicsType type, string model);
	electronicsProduct();
	electronicsType getType();
	string getModel();
	void setModel(string model);
	void displayProductDetails()const;
};

