#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Interface.h"

struct shoppingCart
{
    albumInfo_ item;
    albumInfo_ *next;
};

class Customer : public Interface
{
    private:
        Inventory *inv = nullptr;
        shoppingCart *cart = nullptr;
    public:
        // Constructors
        Customer();
        Customer(Inventory *inventory); // parameterized

        // Interface functions
        void searchInventory(std::string albumTitle);
        void printInventory();
        void addToCart(std::string albumTitle, int quantity);
        void deleteFromCart(std::string albumTitle, int quantity);
        void viewCart();
        void purchaseCart();

        // Unused Interface Functions
        void addToInventory(std::string albumTitle, std::string Artist, float price, int numUnits){};
        void deleteFromInventory(std::string albumTitle){};
        void editArtist(std::string albumTitle, std::string newArtist){};
        void editPrice(std::string albumTitle, float newPrice){};
        void editUnits(std::string albumTitle, int newUnits){};

        // Destructor
        ~Customer();
};

#endif