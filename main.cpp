#include "Inventory.h"

int main()
{
    std::cout << "Program Start" << std::endl;

    Inventory inv;

    inv.addInventory("albtitle1","artist1",10.00,1);
    inv.addInventory("albtitle2","artist2",22.11,21);

    inv.searchInventory("albtitle1");
    inv.searchInventory("albtitle111");

    inv.exportInventory();

    std::cout << "Program End" << std::endl;
    return 0;
}