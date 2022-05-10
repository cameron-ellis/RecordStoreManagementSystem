#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iomanip>

using json = nlohmann::json;

class Inventory
{
    public:
        static Inventory* getInventory();
        void deleteInventory();
        void printInventory();
        bool searchInventory(std::string album_title);
        bool addToInventory(std::string,std::string,float,int);
        bool deleteFromInventory(std::string);
        bool changeQuantity(std::string,int);
        bool importInventory();
        bool exportInventory();
        bool printInventoryItem(nlohmann::detail::iter_impl<nlohmann::basic_json<> >);
    private:
        Inventory();
        ~Inventory();
        static Inventory *instance_;
        json Inv_;
        static int Inv_count;
};

#endif