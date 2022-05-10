#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Interface.h"

class Employee : public Interface
{
    private:
        Inventory *inv;
    public:
        // Constructors
        Employee();
        Employee(Inventory *inventory); // parameterized
        
        // Interface Functions
        void searchInventory(std::string albumTitle);
        void printInventory();
        void addToInventory(std::string albumTitle, std::string Artist, float price, int numUnits);
        void deleteFromInventory(std::string albumTitle);
        void editArtist(std::string albumTitle, std::string newArtist);
        void editPrice(std::string albumTitle, float newPrice);
        void editUnits(std::string albumTitle, int newUnits);

        //Unused Interface Functions
        void addToCart(std::string albumTitle, int quantity){};
        void deleteFromCart(std::string albumTitle, int quantity){};
        void viewCart(){};
        void purchaseCart(){};

        // Destructor
        ~Employee();
};

#endif