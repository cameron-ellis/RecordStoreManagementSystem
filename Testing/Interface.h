#ifndef INTERFACE_H
#define INTERFACE_H
#include "Inventory.h"
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>

class Interface
{
    private:
    public:
        virtual void setInventory(Inventory *inventory) = 0;
        virtual int searchInventory(std::string albumTitle) = 0;
        virtual int printInventory() = 0;
        virtual int addToInventory(std::string albumTitle, std::string Artist, float price, int numUnits) = 0;
        virtual int deleteFromInventory(std::string albumTitle) = 0;
        virtual int addToCart(std::string albumTitle, int quantity) = 0;
        virtual int deleteFromCart(std::string albumTitle, int quantity) = 0;
        virtual int editArtist(std::string albumTitle, std::string newArtist) = 0;
        virtual int editPrice(std::string albumTitle, float newPrice) = 0;
        virtual int editUnits(std::string albumTitle, int newUnits) = 0;
        virtual int viewCart() = 0;
        virtual int purchaseCart() = 0;
        virtual ~Interface() {};
        
};

#endif