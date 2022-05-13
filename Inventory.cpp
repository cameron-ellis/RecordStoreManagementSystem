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

//Parameters: Album Title (string), Artist (string), price (float), number of units (int)
//Will add the item to the inventory. 
//returns true when successful, or false when it cannot add the item due to it already existing.
bool Inventory::addToInventory(std::string album_title, std::string Artist, float price, int numUnits){
    try{
        if(!(this->Inv_.contains(album_title))){
            Inv_[album_title] = { {"artist",Artist}, {"unit_price",price}, {"num_units",numUnits} };
            return true;
        }else{
            throw "Album already exists. Cannot add duplicate.";
        } 
    }
    catch(const char* message){
        std::cerr << message << std::endl;
        return false;
    }
}

//Parameter: Album title to delete (string)
//Searches the inventory and deletes the item if found.
//returns true when successful, or false when it cannot find the album to delete.
bool Inventory::deleteFromInventory(std::string album_title){
    try{
        auto temp = this->Inv_.contains(album_title);
        this->Inv_.erase(this->Inv_.find(album_title));
        
        if(temp){
            std::cout << "Item \"" << album_title << "\" has been deleted.\n" << std::endl;
            return true;
        }else if(!temp){
            std::string errS = "Could not find item \"";
            errS += album_title + "\".";
            throw std::range_error(errS);
        }else{
            std::string errS = "Error: An unknown error has occured.";
            throw std::range_error(errS);
        }
    }
    catch(const std::range_error& e){
        std::cout << e.what() << std::endl;
        return false;
    }
}

//Parameters: Album Title (string), Amount to change inventory count by (int)
//Will change the amount of units of the specified album by adding the number passed to the current count.
//If not enough units exists, will error and abort function.
//returns true when successful, or false when album cannot be found, or when there is not enough stock.
bool Inventory::changeQuantity(std::string album_title,int quantity){
    try{
        auto temp = this->Inv_.find(album_title);
        if(temp != this->Inv_.end()){
            if(temp->value("num_units",0) + quantity >= 0){
                json jtemp;
                jtemp[album_title] = { {"artist",temp->value("artist","false")}, {"unit_price",temp->value("unit_price",0.00)}, {"num_units",temp->value("num_units",0) + quantity} };
                this->Inv_.update(jtemp);
                return true;
            }else{
                std::string errS = "Error: Not enough stock available. No change done. Total stock: ";
                errS += std::to_string(temp->value("num_units",0));
                throw std::range_error(errS);
            }
        }else{
            std::string errS = "Error: Album not found.";
            throw std::range_error(errS);
        }
    }
    catch(const std::range_error& e){
        std::cout << e.what() << std::endl;
        return false;
    }
}

//Parameters: Album Title (string), name to override the current artist name (string).
//Will change the name of the artist for the given album to the provided override name.
//returns true when successful, or false when album cannot be found.
bool Inventory::overrideAlbumAttribute(std::string album_title, std::string artist_name){
    try{
        auto temp = this->Inv_.find(album_title);
        if(temp != this->Inv_.end()){
                json jtemp;
                jtemp[album_title] = { {"artist",artist_name}, {"unit_price",temp->value("unit_price",0.00)}, {"num_units",temp->value("num_units",0)} };
                this->Inv_.update(jtemp);
                return true;
        }else{
            throw "Error: Album not found.";
        }
    }
    catch(const char* message){
        std::cerr << message << std::endl;
        return false;
    }
}

//Parameters: Album Title (string), value to change the album price to (float).
//Will change price of the specified album to the new price given.
//returns true when successful, or false when album cannot be found or if the price is negative.
bool Inventory::overrideAlbumAttribute(std::string album_title, float new_price){
    try{
        auto temp = this->Inv_.find(album_title);
        if(temp != this->Inv_.end()){
            if(new_price >= 0){
                json jtemp;
                jtemp[album_title] = { {"artist",temp->value("artist","false")}, {"unit_price",new_price}, {"num_units",temp->value("num_units",0)} };
                this->Inv_.update(jtemp);
                return true;
            }else{
                throw "Error: Price cannot be negative.";
            }
        }else{
            throw "Error: Album not found.";
        }
    }
    catch(const char* message){
        std::cerr << message << std::endl;
        return false;
    }
}

//Parameters: Album Title (string), value to change the album amount to (int).
//Will change amount in stock of the specified album to the new amount given.
//returns true when successful, or false when album cannot be found or if the amount is negative.
bool Inventory::overrideAlbumAttribute(std::string album_title, int new_amount){
    try{
        auto temp = this->Inv_.find(album_title);
        if(temp != this->Inv_.end()){
            if(new_amount >= 0){
                json jtemp;
                jtemp[album_title] = { {"artist",temp->value("artist","false")}, {"unit_price",temp->value("unit_price",0.00)}, {"num_units",new_amount} };
                this->Inv_.update(jtemp);
                return true;
            }else{
                throw "Error: Unit amount cannot be negative.";
            }
        }else{
            throw "Error: Album not found.";
        }
    }
    catch(const char* message){
        std::cerr << message << std::endl;
        return false;
    }
}

//Parameters: Album Title (string)
//Will search for the specificed album and return a struct containing a copy of its information.
//returns an albumInfo_ struct when successful, or an empty albumInfo_ struct when album cannot be found.
albumInfo_ Inventory::getAlbumInfo(std::string album_title){
    auto temp = this->Inv_.find(album_title);
    albumInfo_ infoStruct = {};
    if(temp != this->Inv_.end()){
        infoStruct.albumName_ = temp.key();
        infoStruct.artistName_ = temp->value("artist","false");
        infoStruct.price_ = temp->value("unit_price",0.00);
        infoStruct.numUnits_ = temp->value("num_units",0);
        return infoStruct;
    }else{
        std::cout << "Album not found." << std::endl;
        return infoStruct;
    }
}

//Will print the contents of the entire inventory.
void Inventory::printInventory(){
    for(auto temp = this->Inv_.begin(); temp != this->Inv_.end(); ++temp){
        this->printInventoryItem(temp);
        std::cout << "\n";
    }
}

//Parameters: Album title (string).
//Searches the inventory for the specific album, and prints the contents, if found.
bool Inventory::searchInventory(std::string album_title){
    auto temp = this->Inv_.find(album_title);
    return this->printInventoryItem(temp);
}

//Parameter: json Iterator pointing to an album.
//Will print out the values of the album the iterator is pointing to.
bool Inventory::printInventoryItem(nlohmann::detail::iter_impl<nlohmann::basic_json<> > temp){
    if(temp != this->Inv_.end()){
        std::cout << "Album: " << temp.key() << std::endl;
        std::cout << "Artist: " << temp->value("artist","false") << std::endl;
        std::cout << std::fixed << std::setprecision(2) << "Price: $" << temp->value("unit_price",0.00) << std::endl;
        std::cout << "Quantity: " << temp->value("num_units",0) << std::endl;
        return true;
    }else{
        std::cout << "Album not found." << std::endl;
        return false;
    }
}

//Loads inventory. Called in constructor.
//returns true when successful, or false when it cannot load in inventory. Failing will load an empty json.
bool Inventory::importInventory(){
    std::ifstream f("Inventory.json");
    if(f){
        f >> this->Inv_;
        return true;
    }else{
        Inv_.clear();
        return false;
    }
}

//Saves inventory. Called in destructor.
//returns true when successful, or false when it cannot write out inventory.
bool Inventory::exportInventory(){
    try{
        std::ofstream f("Inventory.json");
        if(f){
            f << std::setw(4) << this->Inv_ << std::endl;
            return true;
        }else{
            throw "Error: Could not open Inventory file to export.";
        }
    }
    catch(const char* message){
        std::cerr << message << std::endl;
        return false;
    }
}