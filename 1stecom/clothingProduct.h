#pragma once
#include"Product.h"
#include"clothingType.h"

class clothingProduct :public Product {
private:
	static int autoINC;
	clothingType type;
	string size;
	string material;
public:
	clothingProduct();
	clothingProduct(string brand, string name, double price, int quantity, clothingType type, string size, string material);
	clothingType getType();
	string getSize();
	string getMaterial();
	void setSize(string size);
	void setMaterial(string Material);
	void displayProductDetails()const;
};