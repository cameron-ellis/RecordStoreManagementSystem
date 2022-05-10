#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Interface.h"

class Employee : public Interface
{
    private:
        Inventory *inv;
    public:
        Employee();
        Employee(Inventory *inventory);
        ~Employee();
};

#endif