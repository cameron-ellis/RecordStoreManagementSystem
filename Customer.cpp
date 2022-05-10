#include "Customer.h"

// Constructor Implementation
Customer::Customer(){}

Customer::Customer(Inventory *inventory)
{
    this->inv = inventory;
}

Customer::~Customer(){}