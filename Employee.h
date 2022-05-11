#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Interface.h"

class Employee : public Interface
{
    private:
        Inventory *inv = nullptr;
        std::string changelogPat = "InventoryChangeLog.txt";
    public:
        // Constructors
        Employee();
        Employee(Inventory *inventory); // parameterized

        // Set Inventory Function
        void setInventory(Inventory *inventory);
        
        // Interface Functions
        int searchInventory(std::string albumTitle);
        int printInventory();
        int addToInventory(std::string albumTitle, std::string Artist, float price, int numUnits);
        int deleteFromInventory(std::string albumTitle);
        int editArtist(std::string albumTitle, std::string newArtist);
        int editPrice(std::string albumTitle, float newPrice);
        int editUnits(std::string albumTitle, int newUnits);

        //Unused Interface Functions
        int addToCart(std::string albumTitle, int quantity){return 0;};
        int deleteFromCart(std::string albumTitle, int quantity){return 0;};
        int viewCart(){return 0;};
        int purchaseCart(){return 0;};

        // Destructor
        ~Employee();
};

#endif