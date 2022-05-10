#ifndef INTERFACE_H
#define INTERFACE_H
#include "Inventory.h"

class Interface
{
    private:
    public:
        virtual void searchInventory(std::string albumTitle) = 0;
        virtual void printInventory() = 0;
        virtual void addToInventory(std::string albumTitle, std::string Artist, float price, int numUnits) = 0;
        virtual void deleteFromInventory(std::string albumTitle) = 0;
        virtual void addToCart(std::string albumTitle, int quantity) = 0;
        virtual void deleteFromCart(std::string albumTitle, int quantity) = 0;
        virtual void editArtist(std::string albumTitle, std::string newArtist) = 0;
        virtual void editPrice(std::string albumTitle, float newPrice) = 0;
        virtual void editUnits(std::string albumTitle, int newUnits) = 0;
        virtual void viewCart() = 0;
        virtual void purchaseCart() = 0;
        virtual ~Interface() {};
        
};

#endif