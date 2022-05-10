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

// Things to ask for from inventory class
/*
    1.) Getter function to return struct or json object of a particular Record in the Inventory:
       Have function that returns a struct of a particular item within the inventory so its members can be easily accessed
       (or have a function that returns a json object type if that makes more sense to be able to do)
       Ex of potential struct: 
        struct Record {
            std::string albumTitle;
            std::string Artist;
            float price;
            int units;
        };
        Ex Potential Interface:
        Return Item -->(json or struct) Inventory::getRecord(std::string albumTitle); <-- function prototype
        *potential error code in return item could be a -1 quantity and price and empty strings for album title and artist*
    
    2.) Integer Error Codes Returned from each function:
        If Integer error code could be returned from functions it would help in knowing the outcome 
        in the resident interface functions to know what to from there, since there are only prints
        to cout that are returned, it makes it difficult. (Print inventory functions don't really need this obviously,
        but any function that has conditional return situations would be good to have different error codes for.)
    
    3.) Purchase function:
        If a purchase function could be added in which will take in an album title to purchase, and an integer for the number of
        copies to purchase and decrement that from the quantity in the json. That would be very helpful and shouldn't be too much 
        different than the changeQuantity function. This would also check if the quantity was zero and if so, would return a certain error code
        saying the purchase failed so that the customer function could know if the purchase was successful or not.
        Ex Potential Interface:
        Error code return integer --> int Inventory::purchaseItem(std::string albumTitle, int purchaseQuantity);
    
    4.) Return function:
        This function takes in an album title string and a return quantity, it will delete the item out of the purchase for the customer and
        return that quantity to stock. So all this function needs to be able to do is add to the quantity of a given album title, I will handle the rest
        in the actual customer return function.
        Ex Potential Interface:
        Error code return integer --> int Inventory::returnItem(std::string albumTitle, int returnQuantity);
        
*/