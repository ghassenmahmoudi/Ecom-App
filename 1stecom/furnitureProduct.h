#pragma once
#include"Product.h"
#include"furnitureType.h"

using namespace std;

class furnitureProduct:public Product
{
private:
	static int autoINC;
	furnitureType type;
	string dimentions;
	string material;
public:
	furnitureProduct();
	furnitureProduct(string brand, string name, double price, int quantity, furnitureType type, string dimensions, string material);
	furnitureType getType();
	string getMaterial();
	string getDimentions();
	void setMaterial(string material);
	void setDimentions(string dimentions);
	void displayProductDetails()const;
};

