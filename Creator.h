#ifndef CREATOR_H
#define CREATOR_H
#include "Interface.h"
#include "Inventory.h"

class Creator
{
    private:

    public:
        // Generic Constructors
        virtual Interface* CreateEmployeeInterface() = 0;
        virtual Interface* CreateCustomerInterface() = 0;
        //Parameterized Constructors
        virtual Interface* CreateEmployeeInterface(Inventory *inventory) = 0;
        virtual Interface* CreateCustomerInterface(Inventory *inventory) = 0;
        // Dellcator for Interface Object
        virtual void deleteInterface(Interface *interface) = 0;

        virtual ~Creator() {}
};


#endif