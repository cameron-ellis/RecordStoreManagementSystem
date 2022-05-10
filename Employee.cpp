#include "Employee.h"

// Default Constructor
Employee::Employee(){}
// Parameterized Constructor
Employee::Employee(Inventory *inventory)
{
    this->inv = inventory;
}

Employee::~Employee(){}