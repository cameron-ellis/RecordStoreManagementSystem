#include "Inventory.h"

//Default constructor for inventory. Will auto populate inventory on creation.
Inventory::Inventory(){
    this->importInventory();
}

Inventory::~Inventory(){

}

void Inventory::searchInventory(std::string artist_name, std::string album_title){

}

void Inventory::printInventory(){

}

//Parameters: Album TItle (string), Artist (string), price (flaot), number of units (int)
//Will add the item to the inventory. 
void Inventory::addInventory(std::string albumTitle, std::string Artist, float price, int numUnits){
    Inv_[albumTitle] = { {"artist",Artist}, {"unit_price",price}, {"num_units",numUnits} };
}

//Loads inventory.
void Inventory::importInventory(){
    std::ifstream f("Inventory.json");
    if(f){
        f >> this->Inv_;
    }else{
        Inv_.clear();
    }
}

//Save inventory.
void Inventory::exportInventory(){
    std::ofstream f("Inventory.json");
    f << std::setw(4) << this->Inv_ << std::endl;
}