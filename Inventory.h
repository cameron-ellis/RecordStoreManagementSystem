#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory();
        virtual void printInventory();//
        void searchInventory(std::string artist_name, std::string album_title);//
        void addInventory(std::string,std::string,float,int);
        void importInventory();
        void exportInventory();
    private:
        json Inv_;
};

#endif