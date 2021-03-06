#ifndef MENU_H
#define MENU_H
#include "Creator.h"
#include "InterfaceCreator.h"
#include "Inventory.h"
#include "Interface.h"
#include "Customer.h"
#include "Employee.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <limits>

class Menu
{
    private:
    public:
        ///// Constructor and Destructor /////
        Menu(){};
        ~Menu(){};

        ///// Interface Menus /////
        void MainMenu();
        void CustomerMenu();
        void EmployeeMenu();
};

#endif