#include "Inventory.h"
#include "Creator.h"
#include "InterfaceCreator.h"
#include "Interface.h"
#include "Customer.h"
#include "Employee.h"
#include "Menu.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <limits>

int main()
{
    Menu progMenu;
    progMenu.MainMenu();
    return 0;
}