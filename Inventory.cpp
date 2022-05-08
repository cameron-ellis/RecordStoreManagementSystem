#include "Inventory.h"

//Default constructor for inventory. Will auto populate inventory on creation.
Inventory::Inventory(){
    this->importInventory();
}

Inventory::~Inventory(){

}

void Inventory::searchInventory(std::string album_title){
    auto temp = this->Inv_.find(album_title);

    if(temp != this->Inv_.end()){
        std::cout << "Album: " << album_title << std::endl;
        std::cout << "Artist: " << temp->value("artist","false") << std::endl;
        std::cout << "Price: " << temp->value("unit_price",0) << std::endl;
        std::cout << "Quantity: " << temp->value("num_units",0) << std::endl;
    }else{
        std::cout << "Album not found." << std::endl;
    }
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
    try{
        std::ofstream f("Inventory.json");
        if(f){
            f << std::setw(4) << this->Inv_ << std::endl;
        }else{
            throw "Error: Could not open Inventory file to export.";
        }
    }
    catch(const char* message){
        std::cerr << message << std::endl;
    }
}