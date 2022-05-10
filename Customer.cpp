#include "Customer.h"

// Constructor Implementation
Customer::Customer(){}

Customer::Customer(Inventory *inventory)
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