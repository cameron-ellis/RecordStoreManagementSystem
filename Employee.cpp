#include "Employee.h"

// Default Constructor
Employee::Employee(){}
// Parameterized Constructor
Employee::Employee(Inventory *inventory)
{
    this->inv = inventory;
}

// Set Inventory function (if parameterized constructor not used)
void Employee::setInventory(Inventory *inventory)
{
    this->inv = inventory;
}

/********** Interface Functions ***********/

// searchInventory Function:
// searches the inventory object of the Employee interface for the
// specified album title string. Checks to see if the inventory is allocated first,
// if it is not then an error is printed out.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
//  0 -> Search successful
int Employee::searchInventory(std::string albumTitle)
{
    try
    {
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
        }
        this->inv->searchInventory(albumTitle);
        return 0; // search performed successful
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
        return -1; // bad allocation of Inventory
    }
}

// printInventory Function:
// prints the inventory json file to the terminal, checks to see
// if the inventory is allocated first before trying to access it.
// If its not allocated an error is printed out.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
//  0 -> Print successful
int Employee::printInventory()
{
    try
    {
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
        }
        this->inv->printInventory();
        return 0; // search performed successful
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
        return -1; // bad allocation of Inventory
    }
}

// addToInventory Function:
// This function takes in an album title to add to the inventory.
// Will check to see if addition to inventory was successful, and if so
// it will output this change to the changeLog txt file.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
// -2 -> Addition unsuccessful
//  0 -> Addition successful
int Employee::addToInventory(std::string albumTitle, std::string artist, float price, int numUnits)
{
    try
    {
        // Check if Inventory object is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
        }

        // If Inventory object is allocated, attempt to add item to inventory
        bool errCode = this->inv->addToInventory(albumTitle,artist,price,numUnits);
        // Upon success, output change to inventory to changelog
        if (errCode == true)
        {
            // Format string for output
            time_t now = time(0); // get time stamp
            std::string timeStamp = ctime(&now);
            std::stringstream ss;
            ss << "Time Stamp: " << timeStamp << std::endl;
            ss << "Action: New Item Added Inventory" << std::endl;
            ss << "Details: " << std::endl;
            ss << "\t\tAlbum Title: " << albumTitle << " Artist: " << artist << " Price: " << price << " Units Added: " << numUnits << std::endl;
            ss << std::endl;
            // Output string stream to changeLog
            std::ofstream output;
            output.open(changelogPat, std::ios::app);
            output << ss.str();
            output.close();
            return 0;
        }
        else
        {
            // Exit program upon failure, error text will already be printed by addToInventory function
            return -2;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
        return -1; // bad allocation of Inventory
    }
}

// deleteFromInventory Function:
// This function is used to delete an item from the inventory given an album title.
// Will check to see if item can be deleted from the inventory, and if it can, it will
// output the item information of the deleted item to the changelog txt file.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
// -2 -> Deletion Unsuccessful
//  0 -> Deletion performed successfully
int Employee::deleteFromInventory(std::string albumTitle)
{
    try
    {
        // Check if Inventory object is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
        }

        // If Inventory object is allocated, attempt to add item to inventory
        albumInfo_ delItem = this->inv->getAlbumInfo(albumTitle); // get album information for printing
        bool errCode = this->inv->deleteFromInventory(albumTitle);
        // Upon success, output change to inventory to changelog
        if (errCode == true)
        {
            // Format string for output
            time_t now = time(0); // get time stamp
            std::string timeStamp = ctime(&now);
            std::stringstream ss;
            ss << "Time Stamp: " << timeStamp << std::endl;
            ss << "Action: Deleted Item From Inventory" << std::endl;
            ss << "Details: " << std::endl;
            ss << "\t\tAlbum Title: " << delItem.albumName_ << " Artist: " << delItem.artistName_ << " Price: " << delItem.price_ << " Units Deleted: " << delItem.numUnits_ << std::endl;
            ss << std::endl;
            // Output string stream to changeLog txt file
            std::ofstream output;
            output.open(changelogPat, std::ios::app);
            output << ss.str();
            output.close();
            return 0;
        }
        else
        {
            // Exit program upon failure, error text will already be printed by deleteFromInventory function
            return -2;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
        return -1; // bad allocation of Inventory
    }
}

// editArtist Function:
// This function will allow the user to take in an album title, and a new artist
// to overwrite the old artist for the album. First checks to see if the album can be found,
// and if it can, it updates the artist name for the album.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
// -2 -> Edit Artist unsuccessful
//  0 -> Edit Artist successful
int Employee::editArtist(std::string albumTitle, std::string newArtist)
{
    try
    {
        // Check if Inventory object is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
        }

        // If Inventory object is allocated, attempt to add item to inventory
        bool errCode = this->inv->overrideAlbumAttribute(albumTitle,newArtist);
        // Upon success, output change to inventory to changelog
        if (errCode == true)
        {
            // Format string for output
            time_t now = time(0); // get time stamp
            std::string timeStamp = ctime(&now);
            std::stringstream ss;
            ss << "Time Stamp: " << timeStamp << std::endl;
            ss << "Action: Edit Album Artist" << std::endl;
            ss << "Details: " << std::endl;
            ss << "\t\tAlbum Title: " << albumTitle << " New Artist: " << newArtist << std::endl;
            ss << std::endl;
            // Output string stream to changeLog
            std::ofstream output;
            output.open(changelogPat, std::ios::app);
            output << ss.str();
            output.close();
            return 0;
        }
        else
        {
            // Exit program upon failure, error text will already be printed by addToInventory function
            return -2;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
        return -1; // bad allocation of Inventory
    }
}

// editPrice Function:
// This function will allow the user to take in an album title, and a new price
// to overwrite the old price for the album. First checks to see if the album can be found,
// and if it can, it updates the price for the album.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
// -2 -> Edit Price unsuccessful
//  0 -> Edit Price successful
int Employee::editPrice(std::string albumTitle, float newPrice)
{
     try
    {
        // Check if Inventory object is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
        }

        // If Inventory object is allocated, attempt to add item to inventory
        bool errCode = this->inv->overrideAlbumAttribute(albumTitle,newPrice);
        // Upon success, output change to inventory to changelog
        if (errCode == true)
        {
            // Format string for output
            time_t now = time(0); // get time stamp
            std::string timeStamp = ctime(&now);
            std::stringstream ss;
            ss << "Time Stamp: " << timeStamp << std::endl;
            ss << "Action: Edit Album Price" << std::endl;
            ss << "Details: " << std::endl;
            ss << "\t\tAlbum Title: " << albumTitle << " New Price: " << newPrice << std::endl;
            ss << std::endl;
            // Output string stream to changeLog
            std::ofstream output;
            output.open(changelogPat, std::ios::app);
            output << ss.str();
            output.close();
            return 0;
        }
        else
        {
            // Exit program upon failure, error text will already be printed by addToInventory function
            return -2;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
        return -1; // bad allocation of Inventory
    }
}

// editUnits Function:
// This function will allow the user to take in an album title, and a new unit count
// to overwrite the old unit count for the album. First checks to see if the album can be found,
// and if it can, it updates the unit count for the album.
// Error Codes:
// -1 -> Inventory Object not allocated or set correctly
// -2 -> Edit Units unsuccessful
//  0 -> Edit Units successful
int Employee::editUnits(std::string albumTitle, int newUnits)
{
     try
    {
        // Check if Inventory object is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
        }

        // If Inventory object is allocated, attempt to add item to inventory
        bool errCode = this->inv->overrideAlbumAttribute(albumTitle,newUnits);
        // Upon success, output change to inventory to changelog
        if (errCode == true)
        {
            // Format string for output
            time_t now = time(0); // get time stamp
            std::string timeStamp = ctime(&now);
            std::stringstream ss;
            ss << "Time Stamp: " << timeStamp << std::endl;
            ss << "Action: Edit Album Units" << std::endl;
            ss << "Details: " << std::endl;
            ss << "\t\tAlbum Title: " << albumTitle << " New Unit Count: " << newUnits << std::endl;
            ss << std::endl;
            // Output string stream to changeLog
            std::ofstream output;
            output.open(changelogPat, std::ios::app);
            output << ss.str();
            output.close();
            return 0;
        }
        else
        {
            // Exit program upon failure, error text will already be printed by addToInventory function
            return -2;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
        return -1; // bad allocation of Inventory
    }
}

// Destructor
Employee::~Employee(){}