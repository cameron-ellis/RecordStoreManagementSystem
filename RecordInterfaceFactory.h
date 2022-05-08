#ifndef RECORD_Interface_FACTORY_H
#define RECORD_Interface_FACTORY_H
#include <iostream>
#include <string>
#include <fstream>
#include "Inventory.h"
#include "Customer.h"
#include "Employee.h"

class RecordInterfaceFactory
{
    public:
        RecordInterfaceFactory();

        // Employee Interface Constructor
        Employee* CreateEmployeeInterface();

        // Customer Interface Constructor
        Customer* CreateCustomerInterface();

        // Interface deletion method
        void deleteInterface(Inventory *interface);
};

#endif