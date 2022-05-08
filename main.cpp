#include "Inventory.h"

int main()
{
    std::cout << "Program Start" << std::endl;

    Inventory *inv = Inventory::getInventory();

    inv->addInventory("albtitle1","artist1",10.00,1);

    Inventory *inv2 = Inventory::getInventory();

    inv2->addInventory("albtitle2","artist2",22.11,21);

    std::cout << "Searching specific albums:" << std::endl;
    inv->searchInventory("albtitle1");
    inv2->searchInventory("albtitle111");

    std::cout << "\nPrint Inventory:\n" << std::endl;
    inv->printInventory();

    std::cout << "Test1" << std::endl;
    inv->deleteInventory();
    inv = nullptr;
    if(inv != nullptr){
        std::cout << "This might be a problem." << std::endl;
    }
    std::cout << "Test2" << std::endl;
    inv2->deleteInventory();
    inv2 = nullptr;
    std::cout << "Test3" << std::endl;

    std::cout << "Program End" << std::endl;
    return 0;
}