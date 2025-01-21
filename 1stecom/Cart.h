#pragma once
#include <iostream>
#include <string>
#include "Product.h"
#include"Inventory.h"
#include <unordered_map>
using namespace std;



class Cart {
private:
    unordered_map<string, int> cartItems;
public:
    

    void addItem(const string& id, int quantity);

    bool containsItem(const string& productId) const;

    int showQuantity(const string id) const;

    void removeItem(const string& id);

    void showCart()const;


};