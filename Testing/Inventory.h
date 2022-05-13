#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iomanip>

using json = nlohmann::json;

//struct to return requested album attributes.
struct albumInfo_{
    std::string albumName_;
    std::string artistName_;
    float price_;
    int numUnits_;
};

//Singleton design Inventory to make sure multiple inventories may not exist.
class Inventory
{
    public:
        //Inventory manipulation functions
        void deleteInventory();
        static Inventory* getInventory();
        bool addToInventory(std::string,std::string,float,int);
        bool deleteFromInventory(std::string);
        bool changeQuantity(std::string,int);
        bool overrideAlbumAttribute(std::string, std::string);
        bool overrideAlbumAttribute(std::string, float);
        bool overrideAlbumAttribute(std::string, int);

        //Printing and data request.
        albumInfo_ getAlbumInfo(std::string);
        void printInventory();
        bool searchInventory(std::string album_title);
        bool printInventoryItem(nlohmann::detail::iter_impl<nlohmann::basic_json<> >);

        //Import/Export functions.
        bool importInventory();
        bool exportInventory();
    private:
        //contructor and destructor
        Inventory();
        ~Inventory();

        //Values to hold the instance, the inventory object, and a count to know how many open inventories there are.
        static Inventory *instance_;
        json Inv_;
        static int Inv_count;
};

#endif