#include "Employee.h"

// Default Constructor
Employee::Employee(){}
// Parameterized Constructor
Employee::Employee(Inventory *inventory)
{
    this->inv = inventory;
}

// Set Inventory function (if parameterized constructor not used)
void Employee::setInventory(Inventory *inventory)
{
    this->inv = inventory;
}

// Interface Functions
void Employee::searchInventory(std::string albumTitle)
{

}
void Employee::printInventory()
{

}
void Employee::addToInventory(std::string albumTitle, std::string Artist, float price, int numUnits)
{

}
void Employee::deleteFromInventory(std::string albumTitle)
{

}
void Employee::editArtist(std::string albumTitle, std::string newArtist)
{

}
void Employee::editPrice(std::string albumTitle, float newPrice)
{

}
void Employee::editUnits(std::string albumTitle, int newUnits)
{

}

// Destructor
Employee::~Employee(){}