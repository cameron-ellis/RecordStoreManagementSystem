#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Interface.h"

class Customer : public Interface
{
    private:
        Inventory *inv = nullptr;
        std::vector<albumInfo_> shoppingCart;
    public:
        // Constructors
        Customer();
        Customer(Inventory *inventory); // parameterized

        // Set inventory function
        void setInventory(Inventory *inventory);

        // Interface functions
        int searchInventory(std::string albumTitle);
        int printInventory();
        int addToCart(std::string albumTitle, int quantity);
        int deleteFromCart(std::string albumTitle, int quantity);
        int viewCart();
        int purchaseCart();

        // Unused Interface Functions
        int addToInventory(std::string albumTitle, std::string Artist, float price, int numUnits) {};
        int deleteFromInventory(std::string albumTitle) {};
        int editArtist(std::string albumTitle, std::string newArtist) {};
        int editPrice(std::string albumTitle, float newPrice) {};
        int editUnits(std::string albumTitle, int newUnits) {};

        // Destructor
        ~Customer();
};

#endif