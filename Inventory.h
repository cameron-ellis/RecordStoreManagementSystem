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
        virtual void printInventory();
        void searchInventory(std::string album_title);
        void addToInventory(std::string,std::string,float,int);
        void deleteFromInventory(std::string);
        void importInventory();
        void exportInventory();
        void printInventoryItem(nlohmann::basic_json<>::iter_impl<nlohmann::basic_json<> >&);
    private:
        Inventory();
        virtual ~Inventory();
        static Inventory *instance_;
        json Inv_;
        static int Inv_count;
};

#endif