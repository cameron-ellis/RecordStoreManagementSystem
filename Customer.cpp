#include "Customer.h"

// Default Constructor
Customer::Customer(){}
// Parameterized Constructor
Customer::Customer(Inventory *inventory)
{
    this->inv = inventory;
}
// Set Inventory function (if parameterized constructor not used)
void Customer::setInventory(Inventory *inventory)
{
    this->inv = inventory;
}

/***** Interface Functions *****/
// searchInventory Function:
// searches the inventory object of the customer interface for the
// specified album title string. Checks to see if the inventory is allocated first,
// if it is not then an error is printed out.
void Customer::searchInventory(std::string albumTitle)
{
    try
    {
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
        }
        this->inv->searchInventory(albumTitle); 
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
    
}

// printInventory Function:
// prints the inventory json file to the terminal, checks to see
// if the inventory is allocated first before trying to access it.
// If its not allocated an error is printed out.
void Customer::printInventory()
{
    try
    {
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
        }
        this->inv->printInventory(); 
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
}

// addToCart Function:
// This function will take in an album title and the quantity of units that the user wants to purchase,
// and if the number of units is available to purchase it will add this to their shopping cart.
// Checks to see first if inventory is allocated, and then will attempt to add item to cart.
void Customer::addToCart(std::string albumTitle, int quantity)
{
    try
    {
        // Check to make sure Inventory is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return;
        }
        
        // Check to see if album is already in cart and user is trying to add more
        for (int i = 0; i < shoppingCart.size(); i++)
        {
            if (shoppingCart[i].albumName_ == albumTitle)
            {
                bool errCode = this->inv->changeQuantity(albumTitle, -quantity);
                // Check to see if quantity to add can be pulled from inventory
                if (errCode == false)
                {
                    return; // Inventory function will already print out error message
                }
                else
                {
                    // Add additional units of album to shopping cart
                    shoppingCart[i].numUnits_ += quantity;
                    return;
                }
            }
            
        }
        
        // If album was not found in shopping cart, then create a new item for that album and put it onto the list
        // Try to take items out of inventory
        bool errCode = this->inv->changeQuantity(albumTitle, -quantity);
        if (errCode == false)
        {
            return; // Inventory function will already print out error message
        }
        // Add to cart is successful, create album info to add onto vector
        albumInfo_ newItem = this->inv->getAlbumInfo(albumTitle);
        newItem.numUnits_ = quantity;
        shoppingCart.push_back(newItem);
        return;
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
}
// deleteFromCart Function:
// This function takes in a certain album, and a quantity to remove from the cart.
// It will first check to see if the inventory is allocated, and if it is, it will then
// attempt to remove the quantity from the cart and put it back into the inventory stock.
void Customer::deleteFromCart(std::string albumTitle, int quantity)
{
    try
    {
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return;
        }
        // Check to see if item is in cart to remove
        for (int i = 0; i < shoppingCart.size(); i++)
        {   
            if (shoppingCart[i].albumName_ == albumTitle)
            {
                if (shoppingCart[i].numUnits_ > quantity)
                {
                    shoppingCart[i].numUnits_ -= quantity;
                }
                else if (shoppingCart[i].numUnits_ == quantity)
                {
                    shoppingCart.erase(shoppingCart.begin()+i);
                }
                else
                {
                    std::cout << "Error: Tried to remove more items than in cart." << std::endl;
                    std::cout << "Album Name: " << shoppingCart[i].albumName_ << " Units in Cart: " << shoppingCart[i].numUnits_ << std::endl;
                    return;
                }
                break; // break out of loop
            }
        }
        // Put Items Removed from Cart back into Inventory
        this->inv->changeQuantity(albumTitle, quantity);
        return;
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
}

// viewCart Function:
// This function will print the cart to the screen for the user so they can see
// the items and info of their cart at the current moment in time.
void Customer::viewCart()
{
    // Check if shopping cart is empty
    if (shoppingCart.empty() == true)
    {
        std::cout << "Shopping Cart is Empty." << std::endl;
        return;
    }
    // If its not empty, print every Item in shoppingCart
    int totalPrice = 0; // to keep track of total price of purchase
    std::cout << "/t/t/t/t**********Current Shopping Cart**********" << std::endl;
    std::cout << "/tAlbum Name:/t/tArtist:/t/tPrice:/t/tUnit(s):" << std::endl;
    for (int i = 0; i < shoppingCart.size(); i++)
    {
        totalPrice += (shoppingCart[i].numUnits_*shoppingCart[i].price_);
        std::cout << "/t" << shoppingCart[i].albumName_ << "/t" << shoppingCart[i].artistName_ << "/t" << shoppingCart[i].price_ << "/t" << shoppingCart[i].numUnits_ << std::endl;
    }
    std::cout << std::endl;
    std::cout << "/tTotal Price: " << totalPrice << std::endl;
    return;
}

// purchaseCart Function:
// This function will take the current items in the cart, and print the information to a receipt txt file with the time stamp of the purchase.
// It will effectively remove all items from the shopping cart as well so that a new cart can be started.
void Customer::purchaseCart()
{
    // Check if shopping cart is empty
    if (shoppingCart.empty() == true)
    {
        std::cout << "Shopping Cart is Empty." << std::endl;
        return;
    } 
    // If its not empty, create and output every Item in shoppingCart to string stream
    time_t now = time(0); // get time stamp
    std::string timeStamp = ctime(&now);
    std::string receiptName = "Receipt-"+timeStamp; // create txt file name for receipt
    std::stringstream outSS; // string stream for output
    int totalPrice = 0; // to keep track of total price of purchase
    outSS << receiptName << std::endl;
    outSS << "Album Name:/t/t/tArtist:/t/t/tPrice:/t/t/tUnit(s):" << std::endl;
    for (int i = 0; i < shoppingCart.size(); i++)
    {
        totalPrice += (shoppingCart[i].numUnits_*shoppingCart[i].price_);
        outSS << shoppingCart[i].albumName_ << "/t" << shoppingCart[i].artistName_ << "/t" << shoppingCart[i].price_ << "/t" << shoppingCart[i].numUnits_ << std::endl;
    }
    outSS << std::endl;
    outSS << "Total Price: " << totalPrice << std::endl;
    shoppingCart.clear(); // clears shopping cart of all items

    // Open up txt file for receipt and output string stream to it
    std::ofstream outText;
    outText.open(receiptName, std::ios::out);
    outText << outSS.str();
    outText.close();

    return;
}

// Destructor Implementation
Customer::~Customer(){}