#pragma once
#include<iostream>
#include <string>
#include"Customer.h"
#include "Product.h"
using namespace std;

class Order
{
	static int OrderCount;
	int orderID;
	Customer customer;
	unordered_map<Product, int, Product::ProductHash> OrderItems;
	public:
		Order(Customer customer, unordered_map<Product, int, Product::ProductHash> orderedItems);
		Customer getCustomer();
		unordered_map<Product, int, Product::ProductHash> GetOrderItems();
		int GetorderID();
		double theCost();

};