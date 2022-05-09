#include "Inventory.h"

Inventory *Inventory::instance_ = NULL;
int Inventory::Inv_count = 0;

//Default constructor for inventory. Will auto populate inventory on creation.
Inventory::Inventory(){
    std::cout << "Loading Inventory." << std::endl;
    this->importInventory();
}

//Destructor of Inventory. Will export Inventory upon deletion.
Inventory::~Inventory(){
    std::cout << "Saving Inventory." << std::endl;
    this->exportInventory();
}

//Function used to delete inventory instances.
void Inventory::deleteInventory(){
    this->Inv_count--;
    if(Inv_count==0){
        delete this;
    }  
}

//Returns the current instance of the Inventory, as in Inventory pointer.
Inventory* Inventory::getInventory(){
    if(!instance_) {
		instance_ = new Inventory();
	}
    Inv_count++;
	return instance_;
}

//Parameters: Album title (string).
//Searches the inventory for the specific album, and prints the contents, if found.
void Inventory::searchInventory(std::string album_title){
    auto temp = this->Inv_.find(album_title);
    this->printInventoryItem(temp);
}

//Will print the contents of the entire inventory.
void Inventory::printInventory(){
    for(auto temp = this->Inv_.begin(); temp != this->Inv_.end(); ++temp){
        this->printInventoryItem(temp);
        std::cout << "\n";
    }
}
 
//Parameter: json Iterator pointing to an album.
//Will print out the values of the album the iterator is pointing to.
void Inventory::printInventoryItem(nlohmann::basic_json<>::iter_impl<nlohmann::basic_json<> >& temp){
    if(temp != this->Inv_.end()){
        std::cout << "Album: " << temp.key() << std::endl;
        std::cout << "Artist: " << temp->value("artist","false") << std::endl;
        std::cout << std::fixed << std::setprecision(2) << "Price: $" << temp->value("unit_price",0.00) << std::endl;
        std::cout << "Quantity: " << temp->value("num_units",0) << std::endl;
    }else{
        std::cout << "Album not found." << std::endl;
    }
}

//Parameters: Album Title (string), Artist (string), price (flaot), number of units (int)
//Will add the item to the inventory. 
void Inventory::addToInventory(std::string albumTitle, std::string Artist, float price, int numUnits){
    Inv_[albumTitle] = { {"artist",Artist}, {"unit_price",price}, {"num_units",numUnits} };
}

//Parameter: Album title to delete (string)
//Searches the inventory and deletes the item if found.
void Inventory::deleteFromInventory(std::string albumTitle){
    auto temp = this->Inv_.erase(this->Inv_.find(albumTitle));
    if(temp!=this->Inv_.end()){
        std::cout << "Item \"" << albumTitle << "\" has been deleted.\n" << std::endl;
    }else if(temp==this->Inv_.end()){
        std::cout << "Could not find item \"" << albumTitle << "\".\n" << std::endl;
    }else{
        std::cout << "Error: An unknown error has occured." << std::endl;
    }
}

//Loads inventory. Called in constructor.
void Inventory::importInventory(){
    std::ifstream f("Inventory.json");
    if(f){
        f >> this->Inv_;
    }else{
        Inv_.clear();
    }
}

//Saves inventory. Called in destructor.
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