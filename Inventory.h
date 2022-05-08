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
        Inventory();
        virtual ~Inventory();
        virtual void printInventory();//
        void searchInventory(std::string album_title);
        void addInventory(std::string,std::string,float,int);
        void importInventory();
        void exportInventory();
        void printInventoryItem(nlohmann::basic_json<>::iter_impl<nlohmann::basic_json<> >&);
    private:
        json Inv_;
};

#endif