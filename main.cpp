#include "Inventory.h"

int main()
{
    std::cout << "Program Start" << std::endl;

    Inventory *inv = Inventory::getInventory();

    inv->addToInventory("albtitle1","artist1",10.00,1);

    Inventory *inv2 = Inventory::getInventory();

    inv2->addToInventory("albtitle2","artist2",22.11,21);

    std::cout << "Searching specific albums:" << std::endl;
    inv->searchInventory("albtitle1");
    inv2->searchInventory("albtitle111");

    inv->addToInventory("DeleteMe","artistNo",60.00,6);

    std::cout << "\nPrint Inventory:\n" << std::endl;
    inv->printInventory();

    std::cout << "\nDelete From Inventory:\n" << std::endl;

    
    inv2->deleteFromInventory("DeleteMe");
    
    bool check = false;

    check = inv->changeQuantity("albtitle1", 2);
    std::cout << "changeQuntity return value: " << check << "\n\n";
    check = inv->changeQuantity("albtitle1", -3);
    std::cout << "changeQuntity return value: " << check << "\n\n";
    check = inv->changeQuantity("albtitle1", -2);
    std::cout << "changeQuntity return value: " << check << "\n\n";
    
    inv->printInventory();


    std::cout << "\nGet Album info:\n" << std::endl;

    albumInfo_ albInfo = inv->getAlbumInfo("albtitle2");
    std::cout << "Retrieved Album Info albtitle2:\n";
    std::cout << "Album: " << albInfo.albumName_ << std::endl;
    std::cout << "Album: " << albInfo.artistName_ << std::endl;
    std::cout << "Album: " << albInfo.price_ << std::endl;
    std::cout << "Album: " << albInfo.numUnits_ << std::endl;

    albInfo = inv->getAlbumInfo("albtitle2221");
    std::cout << "Retrieved Album Info for missing album:\n";
    std::cout << "Album: " << albInfo.albumName_ << std::endl;
    std::cout << "Album: " << albInfo.artistName_ << std::endl;
    std::cout << "Album: " << albInfo.price_ << std::endl;
    std::cout << "Album: " << albInfo.numUnits_ << std::endl;

    inv->deleteInventory();
    inv = nullptr;
    inv2->deleteInventory();
    inv2 = nullptr;

    std::cout << "Program End" << std::endl;
    return 0;
}