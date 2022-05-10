#include "Customer.h"

// Default Constructor
Customer::Customer(){}
// Parameterized Constructor
Customer::Customer(Inventory *inventory)
{
    this->inv = inventory;
}
// Set Inventory function (if parameterized constructor not used)
void Customer::setInventory(Inventory *inventory)
{
    this->inv = inventory;
}

// Interface Functions
void Customer::searchInventory(std::string albumTitle)
{

}
void Customer::printInventory()
{

}
void Customer::addToCart(std::string albumTitle, int quantity)
{

}
void Customer::deleteFromCart(std::string albumTitle, int quantity)
{

}
void Customer::viewCart()
{

}
void Customer::purchaseCart()
{

}

// Destructor Implementation
Customer::~Customer(){}