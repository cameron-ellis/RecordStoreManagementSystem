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

// Interface Function Testing Code
/*
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

    int errCode;

    // Employee Interface Testing
    // Add function testing
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
    errCode = empInterface->addToInventory(album2,artist2,price2,quantity2); // return -2 album2 already present
    std::cout << errCode << std::endl;
    errCode = empInterface->addToInventory(album4,artist4,price4,quantity4); // return -2 album4 already present
    std::cout << errCode << std::endl;

    std::cout << "Add Album User Input Testing" << std::endl;
    std::string albumTitle;
    std::string artistName;
    float albumPrice;
    int albumUnits;
    std::cout << "Input Album Name: ";
    std::getline(std::cin, albumTitle);
    std::cout << "Input Artist Name: ";
    std::getline(std::cin, artistName);
    while (std::cout << "Input Album Price: " && !(std::cin >> albumPrice)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input price; please re-enter.\n";
    }
    while (std::cout << "Input Album Units: " && !(std::cin >> albumUnits)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input units; please re-enter.\n";
    }
    std::cout << "Adding Item to Inventory..." << std::endl;
    errCode = empInterface->addToInventory(albumTitle,artistName,albumPrice,albumUnits);
    if (errCode == 0)
    {
        std::cout << "Album '" << albumTitle << "' added successfully!" << std::endl;
    }

    // Edit Artist Function Testing
    errCode = empInterface->editArtist(album1,"Snoop Dogg");
    errCode = empInterface->editArtist(album3,"The Beatles");
    std::string inputAlbum;
    std::string inputArtist;
    std::cout << "Enter Album to Change Artist: ";
    std::getline(std::cin,inputAlbum);
    std::cout << "Enter Artist to Change for entered Album: ";
    std::getline(std::cin,inputArtist);
    errCode = empInterface->editArtist(inputAlbum,inputArtist); // should return -2 if can't find album, or 0 if it can find the album

    // Delete function testing
    std::string deleteAlbumTitle;
    std::cout << "Input Album Name: " << std::endl;
    std::getline(std::cin, deleteAlbumTitle);
    std::cout << "Deleting Item..." << std::endl;
    int errCode = empInterface->deleteFromInventory(albumTitle);
    if (errCode == 0)
    {
        std::cout << "Album '" << albumTitle << "' deleted successfully!" << std::endl;
    }

    // Customer Interface Testing
    // Adding and Removing from Cart Testing
    errCode = custInterface->addToCart(album4,2);  // return 0
    std::cout << errCode << std::endl;
    errCode = custInterface->addToCart(album2,2);  // return 0
    std::cout << errCode << std::endl;
    errCode = custInterface->deleteFromCart(album4,1);  // return 0
    std::cout << errCode << std::endl;
    errCode = custInterface->deleteFromCart(album2,5);  // return -2 not enough of album2 in cart to remove
    std::cout << errCode << std::endl;
    errCode = custInterface->viewCart();  // return 0
    std::cout << errCode << std::endl;
    errCode = custInterface->purchaseCart();  // return 0
    std::cout << errCode << std::endl;





    // Deallocate Memory for Inventory and Employee Interface
    custInv->deleteInventory();
    custInv = nullptr;
    custCrtr->deleteInterface(custInterface);
    custInterface = nullptr;
    delete custCrtr;
    custCrtr = nullptr;
    empInv->deleteInventory();
    empInv = nullptr;
    empCrtr->deleteInterface(empInterface);
    empInterface = nullptr;
    delete empCrtr;
    empCrtr = nullptr;
*/

// Inventory Function Testing Code
/*
    std::cout << "Program Start" << std::endl;

    Inventory *inv = Inventory::getInventory();

    inv->addToInventory("albtitle1","artist1",10.00,1);

    Inventory *inv2 = Inventory::getInventory();

    inv2->addToInventory("albtitle2","artist2",22.11,21);

    std::cout << "Searching specific albums:" << std::endl;
    inv->searchInventory("albtitle1");
    inv2->searchInventory("albtitle111");

    inv->addToInventory("DeleteMe","artistNo",60.00,6);

    std::cout << "\nPrint Inventory:\n" << std::endl;
    inv->printInventory();

    std::cout << "\nDelete From Inventory:\n" << std::endl;

    
    inv2->deleteFromInventory("DeleteMe");
    

    std::cout << "\nInventory Edit checks:\n" << std::endl;

    bool check = false;

    check = inv->changeQuantity("albtitle1", 2);
    std::cout << "changeQuantity return value: " << check << "\n\n";
    check = inv->changeQuantity("albtitle1", -3);
    std::cout << "changeQuantity return value: " << check << "\n\n";
    check = inv->changeQuantity("albtitle1", -2);
    std::cout << "changeQuantity return value: " << check << "\n\n";
    
    inv->printInventory();

    std::cout << "\n//Udate values:\n" << std::endl;

    inv2->addToInventory("Override","ThisIsWrong",6.66,69);
    inv->overrideAlbumAttribute("Override", "ThisIsCorrect");
    inv->overrideAlbumAttribute("Override", (float)29.99);
    inv->overrideAlbumAttribute("Override", 16);

    inv->overrideAlbumAttribute("Override", -1);
    inv->overrideAlbumAttribute("This dont Exist", 12);

    inv->printInventory();

    std::cout << "\nGet Album info:\n" << std::endl;

    albumInfo_ albInfo = inv->getAlbumInfo("albtitle2");
    std::cout << "Retrieved Album Info albtitle2:\n";
    std::cout << "Album: " << albInfo.albumName_ << std::endl;
    std::cout << "Album: " << albInfo.artistName_ << std::endl;
    std::cout << "Album: " << albInfo.price_ << std::endl;
    std::cout << "Album: " << albInfo.numUnits_ << std::endl;

    albInfo = inv->getAlbumInfo("albtitle2221");
    std::cout << "Retrieved Album Info for missing album:\n";
    std::cout << "Album: " << albInfo.albumName_ << std::endl;
    std::cout << "Album: " << albInfo.artistName_ << std::endl;
    std::cout << "Album: " << albInfo.price_ << std::endl;
    std::cout << "Album: " << albInfo.numUnits_ << std::endl;

    inv->deleteInventory();
    inv = nullptr;
    inv2->deleteInventory();
    inv2 = nullptr;

    std::cout << "Program End" << std::endl;
*/