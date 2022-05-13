#ifndef INTERFACE_CREATOR_H
#define INTERFACE_CREATOR_H
#include <iostream>
#include <string>
#include <fstream>
#include "Creator.h"
#include "Interface.h"
#include "Inventory.h"
#include "Customer.h"
#include "Employee.h"

class InterfaceCreator : public Creator
{
    public:
        InterfaceCreator();
        ~InterfaceCreator();

        // Employee Interface Constructors
        Interface* CreateEmployeeInterface();
        Interface* CreateEmployeeInterface(Inventory *inventory);

        // Customer Interface Constructors
        Interface* CreateCustomerInterface();
        Interface* CreateCustomerInterface(Inventory *inventory);

        // Interface deletion method
        void deleteInterface(Interface *interface);
};

#endif