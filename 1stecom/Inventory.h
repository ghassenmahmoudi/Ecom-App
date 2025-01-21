#pragma once
#include <iostream>
#include <string>

class Product;

using namespace std;

class Inventory 
{
protected:
	static const int MAX_PRODUCTS = 100; 
	static Product* inventory[MAX_PRODUCTS];
	static unsigned int Product_Number;
public:
	static void setProductList(Product* list);
	static void addProduct();
	static Product SearchProductByID(string id);
	static void deleteProduct(Product product);
	static Product** getInventory();
	static void removeProductByID(string id);
	static void changeProductQuantity(string productId, int newQuantity);
	static void filterProductsByCategory();
	static void filterProductsByPrice();
	static void SearchProductByName();
	static void updateProduct(string id);
	static void displayAllProducts();
	~Inventory();
	

};