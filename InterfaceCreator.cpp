#include "InterfaceCreator.h"

InterfaceCreator::InterfaceCreator(){}

// Employee Interface Constructors
Interface* InterfaceCreator::CreateEmployeeInterface(){
    return new Employee();
}
Interface* InterfaceCreator::CreateEmployeeInterface(Inventory *inventory){
    return new Employee(inventory);
}

// Customer Interface Constructors
Interface* InterfaceCreator::CreateCustomerInterface(){
    return new Customer();
}
Interface* InterfaceCreator::CreateCustomerInterface(Inventory *inventory){
    return new Customer(inventory);
}

// Interface deletion method
void InterfaceCreator::deleteInterface(Interface *interface){
    delete interface;
}