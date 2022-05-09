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
    inv->printInventory();

    inv->deleteInventory();
    inv = nullptr;
    inv2->deleteInventory();
    inv2 = nullptr;

    std::cout << "Program End" << std::endl;
    return 0;
}