#include "Inventory.h"
#include "Creator.h"
#include "InterfaceCreator.h"
#include "Interface.h"
#include "Customer.h"
#include "Employee.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <limits>

int main()
{
    // Allocate memory for interfaces
    Inventory *empInv = Inventory::getInventory();
    Creator *empCrtr = new InterfaceCreator();
    Interface *empInterface = empCrtr->CreateEmployeeInterface(empInv);
    Inventory *custInv = Inventory::getInventory();
    Creator *custCrtr = new InterfaceCreator();
    Interface *custInterface = custCrtr->CreateCustomerInterface(custInv);

    std::string album1 = "album1";
    std::string artist1 = "artist1";
    float price1 = 6.99f;
    int quantity1 = 3;

    std::string album2 = "album2";
    std::string artist2 = "artist2";
    float price2 = 10.99f;
    int quantity2 = 5;

    std::string album3 = "album3";
    std::string artist3 = "artist3";
    float price3 = 8.99f;
    int quantity3 = 2;

    std::string album4 = "album4";
    std::string artist4 = "artist4";
    float price4 = 5.99f;
    int quantity4 = 6;

    std::string album5 = "album5";
    std::string artist5 = "artist5";
    float price5 = 2.99f;
    int quantity5 = 4;

    std::string album6 = "album6";
    std::string artist6 = "artist6";
    float price6 = 3.99f;
    int quantity6 = 4;

    std::string album7 = "album7";
    std::string artist7 = "artist7";
    float price7 = 10.99f;
    int quantity7 = 7;

    int errCode;

    /* ***** Print and Search Testing on Empty Inventory ***** */

    // Print Inventory Function testing (empty Inventory)
    std::cout << "Print Inventory Function testing (empty Inventory)" << std::endl;
    errCode = empInterface->printInventory(); // return 0 and print out "Inventory is Empty"
    std::cout << errCode << std::endl;
    errCode = custInterface->printInventory(); // return 0 and print out "Inventory is Empty"
    std::cout << errCode << std::endl;

    // Search Inventory Function (empty Inventory)
    std::cout << "Search Inventory Function (empty Inventory)" << std::endl;
    errCode = empInterface->searchInventory("Empty Inventory"); // return 0 and print out "Inventory is Empty"
    std::cout << errCode << std::endl;
    errCode = custInterface->searchInventory("Empty Inventory"); // return 0 and print out "Inventory is Empty"
    std::cout << errCode << std::endl;

    /* ********* Employee Interface Testing ********* */

    // Add function testing
    std::cout << "Employee Add Function Testing" << std::endl;
    errCode = empInterface->addToInventory(album1,artist1,price1,quantity1); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->addToInventory(album2,artist2,price2,quantity2); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->addToInventory(album3,artist3,price3,quantity3); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->addToInventory(album4,artist4,price4,quantity4); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->addToInventory(album5,artist5,price5,quantity5); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->addToInventory(album6,artist6,price6,quantity6); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->addToInventory(album7,artist7,price7,quantity7); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->addToInventory(album2,artist2,price2,quantity2); // return -2 album2 already present
    std::cout << errCode << std::endl;
    errCode = empInterface->addToInventory(album4,artist4,price4,quantity4); // return -2 album4 already present
    std::cout << errCode << std::endl;

    // Print Inventory Function testing (items in Inventory)
    std::cout << "Employee Print Inventory Function testing (items in Inventory)" << std::endl;
    errCode = empInterface->printInventory(); // return 0 and print Inventory items that were added above
    std::cout << errCode << std::endl;

    // Search Inventory Function (items in Inventory)
    std::cout << "Employee Search Inventory Function (items in Inventory)" << std::endl;
    errCode = empInterface->searchInventory(album1); // return 0 and print out album1 information
    std::cout << errCode << std::endl;
    errCode = empInterface->searchInventory("alsdjflakdfj"); // return 0 and print out "Album not found"
    std::cout << errCode << std::endl;

    // Edit Artist Function Testing
    std::cout << "Employee Edit Artist Function Testing" << std::endl;
    errCode = empInterface->editArtist(album1,"Snoop Dogg"); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->editArtist(album3,"The Beatles"); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->editArtist("lkasjfdlsaj","The Beatles"); // return -2 album not in Inventory.json
    std::cout << errCode << std::endl;

    // Edit Price Function Testing
    std::cout << "Employee Edit Price Function Testing" << std::endl;
    errCode = empInterface->editPrice(album1,25.99f); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->editPrice(album3,12.99f); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->editPrice("lkasjfdlsaj",1.99f); // return -2 album not in Inventory.json
    std::cout << errCode << std::endl;

    // Edit Units Function Testing
    std::cout << "Employee Edit Units Function Testing" << std::endl;
    errCode = empInterface->editUnits(album1,5); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->editUnits(album3,4); // return 0
    std::cout << errCode << std::endl;
    errCode = empInterface->editUnits("lkasjfdlsaj",25); // return -2 album not in Inventory.json
    std::cout << errCode << std::endl;

    // Delete function testing
    std::cout << "Employee Delete Function Testing" << std::endl;
    errCode = empInterface->deleteFromInventory(album1); // return 0 test deletion of first item
    std::cout << errCode << std::endl;
    errCode = empInterface->deleteFromInventory(album5); // return 0 test deletion of middle item
    std::cout << errCode << std::endl;
    errCode = empInterface->deleteFromInventory(album7); // return 0 test deletion of end item
    std::cout << errCode << std::endl;
    errCode = empInterface->deleteFromInventory("notPresent"); // return -2 album not in inventory
    std::cout << errCode << std::endl;

    /* ********* Customer Interface Testing ********* */

    // Print Inventory testing (items in inventory)
    std::cout << "Customer Print Inventory testing (items in inventory)" << std::endl;
    errCode = custInterface->printInventory();  // return 0 will print all albums in inventory
    std::cout << errCode << std::endl;

    // Search Inventory testing (items in inventory)
    std::cout << "Customer Search Inventory testing (items in inventory)" << std::endl;
    errCode = empInterface->searchInventory(album6); // return 0 and print out album6 information
    std::cout << errCode << std::endl;
    errCode = empInterface->searchInventory("alsdjflakdfj"); // return 0 and print out "Album not found"
    std::cout << errCode << std::endl;

    // Add to Cart testing
    std::cout << "Customer Add to Cart testing" << std::endl;
    errCode = custInterface->addToCart(album4,2);  // return 0
    std::cout << errCode << std::endl;
    errCode = custInterface->addToCart(album2,2);  // return 0
    std::cout << errCode << std::endl;
    errCode = custInterface->addToCart(album3,1);  // return 0
    std::cout << errCode << std::endl;
    errCode = custInterface->addToCart(album4,4);  // return 0 inventory unit count for album 4 should be at 0
    std::cout << errCode << std::endl;
    errCode = custInterface->addToCart(album3,10);  // return -2 not enough units in inventory
    std::cout << errCode << std::endl;
    errCode = custInterface->addToCart(album5,2);  // return -2 album not in inventory
    std::cout << errCode << std::endl;
    
    // Delete from Cart testing
    std::cout << "Customer Delete from Cart testing" << std::endl;
    errCode = custInterface->deleteFromCart(album4,1);  // return 0
    std::cout << errCode << std::endl;
    errCode = custInterface->deleteFromCart(album2,10);  // return -2 not enough album2 in cart to remove
    std::cout << errCode << std::endl;
    errCode = custInterface->deleteFromCart(album4,5);  // return 0 all of album4 units removed from cart
    std::cout << errCode << std::endl;
    errCode = custInterface->deleteFromCart(album5,5);  // return -2 album5 not in cart to remove
    std::cout << errCode << std::endl;

    // View Cart Testing (items in cart)
    std::cout << "Customer View Cart Testing (items in cart)" << std::endl;
    errCode = custInterface->viewCart();  // return 0 print out album2 and album3 unit counts and price
    std::cout << errCode << std::endl;

    // Purchase Cart Testing (items in cart)
    std::cout << "Customer Purchase Cart Testing (items in cart)" << std::endl;
    errCode = custInterface->purchaseCart();  // return 0
    std::cout << errCode << std::endl;

    // View Cart testing (no items in cart)
    std::cout << "Customer View Cart testing (no items in cart)" << std::endl;
    errCode = custInterface->viewCart();  // return 0 prints out that cart is empty
    std::cout << errCode << std::endl;

    // Purchase Cart Testing (no items in cart)
    std::cout << "Customer Purchase Cart Testing (no items in cart)" << std::endl;
    errCode = custInterface->purchaseCart();  // return -2 and says shopping cart is empty
    std::cout << errCode << std::endl;

    /******** Non-allocated Inventory Testing ********/
    std::cout << "Interface Non-allocated Inventory testing" << std::endl;
    // Deallocate Memory for Employee and Customer Inventories
    empInv->deleteInventory();
    empInv = nullptr;
    empInterface->setInventory(nullptr);
    custInv->deleteInventory();
    custInv = nullptr;
    custInterface->setInventory(nullptr);
    
    // Employee Testing
    std::cout << "Employee Interface Non-allocated Inventory testing" << std::endl;
    errCode = empInterface->printInventory(); // return -1
    std::cout << errCode << std::endl;
    errCode = empInterface->searchInventory("Empty Inventory"); // return -1
    std::cout << errCode << std::endl;
    errCode = empInterface->addToInventory(album1,artist1,price1,quantity1); // return -1
    std::cout << errCode << std::endl;
    errCode = empInterface->editArtist(album1,"Snoop Dogg"); // return -1
    std::cout << errCode << std::endl;
    errCode = empInterface->editPrice(album1,25.99f); // return -1
    std::cout << errCode << std::endl;
    errCode = empInterface->editUnits(album1,5); // return -1
    std::cout << errCode << std::endl;
    errCode = empInterface->deleteFromInventory(album1); // return -1
    std::cout << errCode << std::endl;

    // Customer Testing
    std::cout << "Customer Interface Non-allocated Inventory testing" << std::endl;
    errCode = custInterface->printInventory();  // return -1
    std::cout << errCode << std::endl;
    errCode = custInterface->searchInventory("Empty Inventory"); // return -1
    std::cout << errCode << std::endl;
    errCode = custInterface->addToCart(album4,2);  // return -1
    std::cout << errCode << std::endl;
    errCode = custInterface->deleteFromCart(album4,1);  // return -1
    std::cout << errCode << std::endl;

    // Delete Allocated Interfaces
    custCrtr->deleteInterface(custInterface);
    custInterface = nullptr;
    delete custCrtr;
    custCrtr = nullptr;
    empCrtr->deleteInterface(empInterface);
    empInterface = nullptr;
    delete empCrtr;
    empCrtr = nullptr;

    std::cout << "Tests Completed" << std::endl;
    return 0;
}