#include "Cart.h"


void Cart::addItem(const string& id, int quantity)
{
    
         
        try {
            Product product(Inventory::SearchProductByID(id));
            if (quantity > product.getquantity()) {
                cout << "Not enough stock. Available stock is: " << product.getquantity() << endl;
                
            }

            if (cartItems.count(id) > 0) {
                cartItems[id] += quantity;
            }
            else {
                
                cartItems.insert({ id,quantity });
            }

            product.decreasequantity(quantity);
        }
        catch (int e)
        {
            cout << "Product not found." << endl;
        }

    
}

bool Cart::containsItem(const string& productId) const
{
    return cartItems.count(productId) > 0;
}

int Cart::showQuantity(const string id) const
{
    if (cartItems.count(id)>0) {
        auto it = cartItems.find(id);
        return (it->second);
    }
    else {
        return 0; 
    }
}

void Cart::removeItem(const string& id)
{
    cartItems.erase(id);
}

void Cart::showCart() const

{
    if (cartItems.empty()) {
        cout << "Cart is empty" << endl;
    }
    else {
        cout << "You Have In Your Cart: " << endl;
        for (const auto& entry : cartItems) {
            const string& productId = entry.first;
            int quantity = entry.second;
                Product product (Inventory::SearchProductByID(productId));
                 
                    cout << "Product: " << product.name << endl;
                    cout << "ID: " << product.id << endl;
                    cout << "Quantity: " << quantity << endl;
                    cout << "Price per unit: " << product.price << endl;
                    cout << "Total Price: " << quantity * (product.price) << endl;
                    cout << "------------------------" << endl;

    
        }
    }
}
