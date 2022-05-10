#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Interface.h"

class Customer : public Interface
{
    private:
        Inventory *inv;
    public:
        Customer();
        Customer(Inventory *inventory);
        ~Customer();
};

#endif