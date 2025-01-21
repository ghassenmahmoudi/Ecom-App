#include "Inventory.h"
#include "furnitureProduct.h"
#include "clothingProduct.h"
#include"electronicsProduct.h"
#include "Cart.h"
#include "Category.h"
#include "Product.h"
#include <algorithm>




Product* Inventory::inventory[MAX_PRODUCTS] = { nullptr };
unsigned int Inventory::Product_Number=0;


void Inventory::setProductList(Product* list)
{
	*inventory = list;
}

void Inventory::addProduct()
{
    int choice;

    cout << "Select your added product category:\n";
    cout << " 1. Furniture\n";
    cout << " 2. Electronics\n";
    cout << " 3. Clothing\n";
    

    cin >> choice;
    switch (choice) {
    case 1:
        inventory[Product_Number] = new furnitureProduct();
        Product_Number++;
        break;
    case 2:
        inventory[Product_Number] = new electronicsProduct();
        Product_Number++;
        break;
    case 3:
        inventory[Product_Number] = new clothingProduct();
        Product_Number++;
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }

}


void Inventory::deleteProduct(Product product)
{
    for ( int i = 0; i < Product_Number; i++) {
        if (*inventory[i] == product) { 
            delete inventory[i]; 
            for (int j = i; j < Product_Number ; ++j) {
                inventory[j] = inventory[j + 1];
            }
            inventory[Product_Number - 1] = nullptr; 
            Product_Number--; 
            break;
            
        }
       
    }
    
}

Product** Inventory::getInventory()
{
    return inventory;
}

void Inventory::removeProductByID(string id)
{
    for ( int i = 0; i < Product_Number; i++) 
    {
        if (inventory[i]->getid() == id) 
        { 
            deleteProduct(*inventory[i]);
            return;
        }
    }
    cout << "Product does not exist!" << endl;
}

void Inventory::changeProductQuantity(string productId, int newQuantity)
{
    for (int i = 0; i < Product_Number; i++) {
        if ((inventory[i]->getid()) == productId)
        {
            inventory[i]->setquantity(newQuantity);
        }
    }
}

void Inventory::filterProductsByCategory()
{
    cout << "Select your filtered product category:\n";
    cout << "1. Furniture\n";
    cout << "2. Electronic\n";
    cout << "3. Clothing" << endl;
    int choice;
    cin >> choice;
    Category category=Category::EMPTY;
    switch (choice)
    {
    case 1:
        cout << "FURNITURE\n";
        category = Category::FURNITURE;
        break;
    case 2:
        cout << "ELECTRONICS\n";
        category = Category::ELECTRONICS;
        break;
    case 3:
        cout << "CLOTHING\n";
        category = Category::CLOTHING;
        break;
    default:
        cout << "Invalid Choice!" << endl;
        break;
    }

    for (int i = 0; i < Product_Number; i++)
    {
        if ((inventory[i]->getcategory()) == category)
        {
            inventory[i]->displayProductDetails();
        }
    }
}

void Inventory::filterProductsByPrice()
{
    int minP, maxP;
    cout << "Enter your Highest price : \n";
    cin >> maxP;
    cout << "Enter your Lowest price : \n";
    cin >> minP;
    for (int i = 0; i < Product_Number; i++)
    {
        if (inventory[i]->getprice()<=maxP && inventory[i]->getprice()>=minP)
        {
            inventory[i]->displayProductDetails();
        }
    }
}

void Inventory::SearchProductByName()
{
    cout << "Enter the Name of the product you looking for:  \n";
    string name;
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    for (int i = 0; i < Product_Number; i++)
    {
        if (inventory[i]->getname().find(name) != string::npos)
        {
            inventory[i]->displayProductDetails();
        }
    }
}

Product Inventory::SearchProductByID(string id)
{
    string theID;
    for (int i = 0; i < Product_Number; i++)
    {
        theID= inventory[i]->getid();
        if (id.compare(theID) == 0)
        {
            return *(inventory[i]);
        }
    }    
    throw 1;
    

}

void Inventory::updateProduct(string id)
{

    Product* productPtr = nullptr;
    for (int i = 0; i < Product_Number; ++i) {
        if (inventory[i]->getid() == id) {
            productPtr = inventory[i];
            break;
        }
    }

    if (productPtr!=nullptr) {
        productPtr->updateProduct();
        cout << "Product updated successfully." << endl;
    }
    else {
        cout << "Product not found." << endl;
    }

}

void Inventory::displayAllProducts()
{
    for (int i = 0; i < Product_Number; i++)
    {
            inventory[i]->displayProductDetails();
    }
}

Inventory::~Inventory()
{
    for (unsigned int i = 0; i < MAX_PRODUCTS; ++i)
    {
        delete inventory[i];
    }
}


