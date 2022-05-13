#include "Customer.h"

#define TAX 0.07

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
// searches the inventory object of the Customer interface for the
// specified album title string. Checks to see if the inventory is allocated first,
// if it is not then an error is printed out.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
//  0 -> Search successful
int Customer::searchInventory(std::string albumTitle)
{
    try
    {
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return -1;
        }
        this->inv->searchInventory(albumTitle);
        return 0;
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
    return 0;
}

// printInventory Function:
// prints the inventory json file to the terminal, checks to see
// if the inventory is allocated first before trying to access it.
// If its not allocated an error is printed out.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
//  0 -> Print successful
int Customer::printInventory()
{
    try
    {
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return -1;
        }
        this->inv->printInventory();
        return 0;
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
    return 0;
}

// addToCart Function:
// This function will take in an album title and the quantity of units that the user wants to purchase,
// and if the number of units is available to purchase it will add this to their shopping cart.
// Checks to see first if inventory is allocated, and then will attempt to add item to cart.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
// -2 -> Add to Cart unsuccessful
//  0 -> Add to Cart successful
int Customer::addToCart(std::string albumTitle, int quantity)
{
    try
    {
        // Check to make sure Inventory is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return -1;
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
                    return -2; // Inventory function will already print out error message
                }
                else
                {
                    // Add additional units of album to shopping cart
                    shoppingCart[i].numUnits_ += quantity;
                    return 0;
                }
            }
            
        }
        
        // If album was not found in shopping cart, then create a new item for that album and put it onto the list
        // Try to take items out of inventory
        bool errCode = this->inv->changeQuantity(albumTitle, -quantity);
        if (errCode == false)
        {
            return -2; // Inventory function will already print out error message
        }
        // Add to cart is successful, create album info to add onto vector
        albumInfo_ newItem = this->inv->getAlbumInfo(albumTitle);
        newItem.numUnits_ = quantity;
        shoppingCart.push_back(newItem);
        return 0;
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
    return 0;
}
// deleteFromCart Function:
// This function takes in a certain album, and a quantity to remove from the cart.
// It will first check to see if the inventory is allocated, and if it is, it will then
// attempt to remove the quantity from the cart and put it back into the inventory stock.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
// -2 -> Delete from Cart unsuccessful
//  0 -> Delete from Cart successful
int Customer::deleteFromCart(std::string albumTitle, int quantity)
{
    try
    {
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return -1;
        }
        // Check to see if item is in cart to remove
        for (int i = 0; i < shoppingCart.size(); i++)
        {
            // If album is found, there are multiple remove conditions
            if (shoppingCart[i].albumName_ == albumTitle)
            {
                if (shoppingCart[i].numUnits_ > quantity)
                {
                    // More units in cart than being remove, decrement units in shoppin cart by quantity
                    shoppingCart[i].numUnits_ -= quantity;
                    // Put Items Removed from Cart back into Inventory
                    this->inv->changeQuantity(albumTitle, quantity);
                    return 0;
                }
                else if (shoppingCart[i].numUnits_ == quantity)
                {
                    // Equal number of units in shoppin cart, remove the entire item from the cart
                    shoppingCart.erase(shoppingCart.begin()+i);
                    // Put Items Removed from Cart back into Inventory
                    this->inv->changeQuantity(albumTitle, quantity);
                    return 0;
                }
                else
                {
                    // If not enough units in cart, deletion fails
                    std::cout << "Error: Tried to remove more items than in cart." << std::endl;
                    std::cout << "Album Name: " << shoppingCart[i].albumName_ << " Units in Cart: " << shoppingCart[i].numUnits_ << std::endl;
                    return -2;
                }
            }
        }
        // Album not found in Cart, print current cart to show user what they have
        std::cout << "Album not in Cart, current Cart below:" << std::endl;
        this->viewCart();
        return -2; 
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
    return 0;
}

// viewCart Function:
// This function will print the cart to the screen for the user so they can see
// the items and info of their cart at the current moment in time.
// Error Codes:
//  0 -> View Cart successful
int Customer::viewCart()
{
    // Check if shopping cart is empty
    if (shoppingCart.empty() == true)
    {
        std::cout << "Shopping Cart is Empty." << std::endl;
        return 0;
    }
    // If its not empty, print every Item in shoppingCart
    float totalPrice = 0.00f; // to keep track of total price of purchase
    std::cout << "**********Current Shopping Cart**********" << std::endl;
    std::cout << "Album Name:\t\tArtist:\t\tPrice:\t\tUnit(s):" << std::endl;
    for (int i = 0; i < shoppingCart.size(); i++)
    {
        totalPrice += (shoppingCart[i].numUnits_*shoppingCart[i].price_);
        std::cout << shoppingCart[i].albumName_ << "\t\t" << shoppingCart[i].artistName_ << "\t\t" << shoppingCart[i].price_ << "\t\t" << shoppingCart[i].numUnits_ << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Total Price: " << totalPrice << std::endl;
    return 0;
}

// purchaseCart Function:
// This function will take the current items in the cart, and print the information to a receipt txt file with the time stamp of the purchase.
// It will effectively remove all items from the shopping cart as well so that a new cart can be started.
// Error Codes:
//  0 -> View Cart successful
// -2 -> Cart is empty
int Customer::purchaseCart()
{
    // Check if shopping cart is empty
    if (shoppingCart.empty() == true)
    {
        std::cout << "Shopping Cart is Empty." << std::endl;
        return -2;
    } 
    // If its not empty, create and output every Item in shoppingCart to string stream
    time_t now = time(0); // get time stamp
    std::string timeStamp = ctime(&now);
    std::string receiptName = "Receipt-"+timeStamp+".txt"; // create txt file name for receipt
    std::stringstream outSS; // string stream for output
    float totalPrice = 0.00f; // to keep track of total price of purchase
    outSS << "      ╔════════════════╗      " << std::endl;     //reciept header
    outSS << "      ║Spinnin' Records║      " << std::endl;
    outSS << "      ╚════════════════╝      " << std::endl;
    outSS << "       411 S 6th Street       " << std::endl;
    outSS << "      Columbia MO, 65211      " << std::endl;
    outSS << "______________________________" << std::endl;
    outSS << timeStamp << std::endl;
    outSS << "Purchase (total "<<shoppingCart.size()<<" items):\n"<<std::endl;

    for (int i = 0; i < shoppingCart.size(); i++)       //iterate through cart to list all items
    {
        totalPrice += (shoppingCart[i].numUnits_*shoppingCart[i].price_);
        outSS << shoppingCart[i].albumName_<<"(x"<<shoppingCart[i].numUnits_<<")"<< "\n-" << shoppingCart[i].artistName_ << std::endl;
        outSS <<std::setw(30)<<std::right<< std::setprecision(2)<<std::fixed <<shoppingCart[i].price_ << std::endl;
    }
    outSS << std::endl; 
    outSS << "Subtotal:" << std::setprecision(2)<<std::fixed<<std::right<<std::setw(21)<< totalPrice << std::endl;   //use setprecision to ensure cents are printed
    outSS << "Tax:" << std::setprecision(2)<<std::fixed<<std::right<<std::setw(26)<<(totalPrice*TAX)<<std::endl;
    outSS << "Total:"<< std::setprecision(2)<<std::fixed<<std::right<<std::setw(24)<< (totalPrice+(totalPrice*TAX))<<std::endl;

    outSS << "______________________________" << std::endl;
    outSS << "   Thanks for shopping with   \n       Spinnin' Records       \n▼▼▼▼▼▼▼▼▼Check us out▼▼▼▼▼▼▼▼▼\n    www.spinninrecords.com    "<<std::endl;

    shoppingCart.clear(); // clears shopping cart of all items

    // Open up txt file for receipt and output string stream to it
    std::ofstream outText;
    outText.open(receiptName, std::ios::out);
    outText << outSS.str();
    outText.close();
    // Purchase Cart Successful
    return 0;
}

// Destructor Implementation
Customer::~Customer(){}