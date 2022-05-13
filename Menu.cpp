#include "Menu.h"

/************************ Main Menu Function **************************/
void Menu::MainMenu()
{
    int userSelect = 0;
    std::string temp = "";
    while(userSelect!=3)
    {
        std::cout << "************** Record Store Inventory System **************" << std::endl;
        std::cout << "Please Select a User Type (input corresponding number)" << std::endl;
        std::cout << "\t\t1.) Customer" << std::endl;
        std::cout << "\t\t2.) Employee" << std::endl;
        std::cout << "\t\t3.) Logout" << std::endl;
        std::cout << "Select User: ";

        std::getline(std::cin, temp);
        userSelect = std::stoi(temp);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(userSelect){
            case 1 :
                std::system("clear");
                std::cout << "Customer User Selected" << std::endl;
                sleep(2);
                std::system("clear");
                this->CustomerMenu();
                break;
            case 2 :
                std::system("clear");
                std::cout << "Employee User Selected" << std::endl;
                sleep(2);
                std::system("clear");
                this->EmployeeMenu();
                break;
            case 3 :
                std::system("clear");
                std::cout << "Logged Out" << std::endl;
                sleep(2);
                std::system("clear");
                break;
            default :
                std::system("clear");
                std::cout << "Invalid input; please re-enter." << std::endl;
                sleep(2);
                std::system("clear");
        }
    }
    return;
}

/************************ Customer Menu Function **************************/
void Menu::CustomerMenu()
{
    // Allocate Inventory Singleton and Customer Interface
    Inventory *custInv = Inventory::getInventory();
    Creator *custCrtr = new InterfaceCreator();
    Interface *custInterface = custCrtr->CreateCustomerInterface(custInv);

    while(true)
    {
      std::cout << "************** Record Store Inventory System **************" << std::endl;
      std::cout << "******************* Customer Interface ********************" << std::endl;
      std::cout << "Please Select Customer Action (input corresponding number)" << std::endl;
      std::cout << "\t\t1.) Print Inventory" << std::endl;
      std::cout << "\t\t2.) Search for Item" << std::endl;
      std::cout << "\t\t3.) Add Item to Cart" << std::endl;
      std::cout << "\t\t4.) Delete Item from Cart" << std::endl;
      std::cout << "\t\t5.) View Cart" << std::endl;
      std::cout << "\t\t6.) Checkout Cart" << std::endl;
      std::cout << "\t\t7.) Logout Customer" << std::endl;
      std::string userSelect;
      std::cout << "Select Action: ";
      std::getline(std::cin, userSelect);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (userSelect == "1") { // Print Inventory Function
          std::system("clear");
          std::cout << "Printing Inventory..." << std::endl;
          custInterface->printInventory();
      }
      else if (userSelect == "2") { // Search for Inventory Item
          std::system("clear");
          std::string albumTitle;
          std::cout << "Input Album Name: ";
          std::getline(std::cin, albumTitle);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Searching for Item..." << std::endl;
          custInterface->searchInventory(albumTitle);
      }
      else if (userSelect == "3") { // Add Item to Cart
          std::system("clear");
          std::string albumTitle;
          int quantity;
          std::cout << "Input Album Name: ";
          std::getline(std::cin, albumTitle);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          while (std::cout << "Input Quantity: " && !(std::cin >> quantity)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            quantity = 0;
            std::cout << "Invalid input quantity; please re-enter.\n";
          }
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Adding Item to Cart..." << std::endl;
          int errCode = custInterface->addToCart(albumTitle,quantity);
          if (errCode == 0)
          {
              std::cout << "Album '" << albumTitle << "' added to cart successfully!" << std::endl;
          }
          sleep(3);
          std::system("clear");
      }
      else if (userSelect == "4") { // Delete Item from Cart
          std::system("clear");
          std::string albumTitle;
          int quantity;
          std::cout << "Input Album Name: ";
          std::getline(std::cin, albumTitle);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          while (std::cout << "Input Quantity: " && !(std::cin >> quantity)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            quantity = 0;
            std::cout << "Invalid input quantity; please re-enter.\n";
          }
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Deleting Item from Cart..." << std::endl;
          int errCode = custInterface->deleteFromCart(albumTitle,quantity);
          if (errCode == 0)
          {
              std::cout << "Album '" << albumTitle << "' deleted from cart successfully!" << std::endl;
          }
          sleep(3);
          std::system("clear");
      }
      else if (userSelect == "5") { // View Cart
          std::system("clear");
          std::cout << "Printing Cart..." << std::endl;
          int errCode = custInterface->viewCart();
      }
      else if (userSelect == "6") { // Checkout Cart
          std::system("clear");
          std::cout << "Checking Out Cart..." << std::endl;
          int errCode = custInterface->purchaseCart();
          if (errCode == 0)
          {
              std::cout << "Cart Purchased Successfully!" << std::endl;
          }
          sleep(3);
          std::system("clear");
      }
      else if (userSelect == "7") { // Customer User Logout
          std::system("clear");
          std::cout << "Customer Logged Out" << std::endl;
          sleep(2);
          std::system("clear");
          break;
      }
      else {
          std::system("clear");
          std::cout << "Invalid input; please re-enter." << std::endl;
          sleep(2);
          std::system("clear");
      }
    }
    // Deallocate Memory for Inventory and Employee Interface
    custInv->deleteInventory();
    custInv = nullptr;
    custCrtr->deleteInterface(custInterface);
    custInterface = nullptr;
    delete custCrtr;
    custCrtr = nullptr;
    std::system("clear");
    return;
}

/************************ Employee Menu Function **************************/
void Menu::EmployeeMenu()
{
    // Allocate Inventory Singleton and Employee Interface
    Inventory *empInv = Inventory::getInventory();
    Creator *empCrtr = new InterfaceCreator();
    Interface *empInterface = empCrtr->CreateEmployeeInterface(empInv);

    while(true)
    {
      std::cout << "************** Record Store Inventory System **************" << std::endl;
      std::cout << "******************* Employee Interface ********************" << std::endl;
      std::cout << "Please Select Employee Action (input corresponding number)" << std::endl;
      std::cout << "\t\t1.) Print Inventory" << std::endl;
      std::cout << "\t\t2.) Search for Item" << std::endl;
      std::cout << "\t\t3.) Add Item to Inventory" << std::endl;
      std::cout << "\t\t4.) Delete Item from Inventory" << std::endl;
      std::cout << "\t\t5.) Edit Album Artist" << std::endl;
      std::cout << "\t\t6.) Edit Album Price" << std::endl;
      std::cout << "\t\t7.) Edit Album Units" << std::endl;
      std::cout << "\t\t8.) Logout Employee" << std::endl;
      std::string userSelect;
      std::cout << "Select Action: ";
      std::getline(std::cin, userSelect);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (userSelect == "1") { // Print Inventory
          std::system("clear");
          std::cout << "Printing Inventory..." << std::endl;
          empInterface->printInventory();
      }
      else if (userSelect == "2") { // Search for Inventory Item
          std::system("clear");
          std::string albumTitle;
          std::cout << "Input Album Name: ";
          std::getline(std::cin, albumTitle);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Searching for Item..." << std::endl;
          empInterface->searchInventory(albumTitle);
      }
      else if (userSelect == "3") { // Add Item to Inventory
          std::system("clear");
          std::string albumTitle;
          std::string artistName;
          float albumPrice;
          int albumUnits;
          std::cout << "Input Album Name: ";
          std::getline(std::cin, albumTitle);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Input Artist Name: ";
          std::getline(std::cin, artistName);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          while (std::cout << "Input Album Price: " && !(std::cin >> albumPrice)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            albumPrice = 0.00f;
            std::cout << "Invalid input price; please re-enter.\n";
          }
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          while (std::cout << "Input Album Units: " && !(std::cin >> albumUnits)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            albumUnits = 0;
            std::cout << "Invalid input units; please re-enter.\n";
          }
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Adding Item to Inventory..." << std::endl;
          int errCode = empInterface->addToInventory(albumTitle,artistName,albumPrice,albumUnits);
          if (errCode == 0)
          {
              std::cout << "Album '" << albumTitle << "' added successfully!" << std::endl;
          }
          sleep(3);
          std::system("clear");
      }
      else if (userSelect == "4") { // Delete Item from Inventory
          std::system("clear");
          std::string albumTitle;
          std::cout << "Input Album Name: ";
          std::getline(std::cin, albumTitle);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Deleting Item..." << std::endl;
          int errCode = empInterface->deleteFromInventory(albumTitle);
          if (errCode == 0)
          {
              std::cout << "Album '" << albumTitle << "' deleted successfully!" << std::endl;
          }
          sleep(3);
          std::system("clear");
      }
      else if (userSelect == "5") { // Edit Album Artist
          std::system("clear");
          std::string albumTitle;
          std::string artistName;
          std::cout << "Input Album Name: ";
          std::getline(std::cin, albumTitle);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Input Artist Name: ";
          std::getline(std::cin, artistName);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Updating Album Artist..." << std::endl;
          int errCode = empInterface->editArtist(albumTitle,artistName);
          if (errCode == 0)
          {
              std::cout << "Album '" << albumTitle << "' artist updated to '" << artistName << "' successfully!" << std::endl;
          }
          sleep(3);
          std::system("clear");
      }
      else if (userSelect == "6") { // Edit Album Price
          std::system("clear");
          std::string albumTitle;
          float albumPrice;
          std::cout << "Input Album Name: ";
          std::getline(std::cin, albumTitle);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          while (std::cout << "Input Album Price: " && !(std::cin >> albumPrice)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            albumPrice = 0.00f;
            std::cout << "Invalid input price; please re-enter.\n";
          }
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Updating Album Artist..." << std::endl;
          int errCode = empInterface->editPrice(albumTitle,albumPrice);
          if (errCode == 0)
          {
              std::cout << "Album '" << albumTitle << "' price updated to '" << albumPrice << "' successfully!" << std::endl;
          }
          sleep(3);
          std::system("clear");
      }
      else if (userSelect == "7") { // Edit Album Units
          std::system("clear");
          std::string albumTitle;
          int albumUnits;
          std::cout << "Input Album Name: ";
          std::getline(std::cin, albumTitle);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          while (std::cout << "Input Album Units: " && !(std::cin >> albumUnits)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            albumUnits = 0;
            std::cout << "Invalid input price; please re-enter.\n";
          }
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Updating Album Artist..." << std::endl;
          int errCode = empInterface->editUnits(albumTitle,albumUnits);
          if (errCode == 0)
          {
              std::cout << "Album '" << albumTitle << "' unit count updated to '" << albumUnits << "' successfully!" << std::endl;
          }
          sleep(3);
          std::system("clear");
      }
      else if (userSelect == "8") { // Employee User Logout
          std::system("clear");
          std::cout << "Employee Logged Out" << std::endl;
          sleep(2);
          std::system("clear");
          break;
      }
      else {
          std::system("clear");
          std::cout << "Invalid input; please re-enter." << std::endl;
          sleep(2);
          std::system("clear");
      }
    }
    // Deallocate Memory for Inventory and Employee Interface
    empInv->deleteInventory();
    empInv = nullptr;
    empCrtr->deleteInterface(empInterface);
    empInterface = nullptr;
    delete empCrtr;
    empCrtr = nullptr;
    std::system("clear");
    return;
}