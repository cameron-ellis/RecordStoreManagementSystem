#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <string>
#include <fstream>

struct Item
{
    std::string artist_name;
    std::string album_title;
    std::string genre;
    std::string media_type;
    float unit_cost;
    float total_cost;
    float unit_price;
    int num_units;
};


struct ItemList
{
    Item i;
    ItemList *next;
};


class Interface
{
    protected:
        ItemList *inv_head;

    public:
        Interface();
        void searchInventory(std::string artist_name, std::string album_title, std::string media_type);
        virtual void printInventory();
        virtual ~Interface() {};

};






#endif