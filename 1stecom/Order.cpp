#include "Order.h"

int Order::OrderCount = 0;
Order::Order(Customer customer, unordered_map<Product, int, Product::ProductHash> OrderItems)
{
	OrderCount++;
	this->customer = customer;
	this->orderID = OrderCount;
	this->OrderItems.insert(OrderItems.begin(), OrderItems.end());
}

Customer Order::getCustomer()
{
	return customer;
}

unordered_map<Product, int, Product::ProductHash> Order::GetOrderItems()
{
	return OrderItems;
}

int Order::GetorderID()
{
	return orderID;
}

double Order::theCost()
{
	double cost = 0.0;
	for (const auto& entry : OrderItems)
	{
		Product TheProduct ( entry.first);
		cost += TheProduct.getprice() * (entry.second);

	}
	return cost;

}
