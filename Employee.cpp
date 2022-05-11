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

// Interface Functions
// searchInventory Function:
// searches the inventory object of the Employee interface for the
// specified album title string. Checks to see if the inventory is allocated first,
// if it is not then an error is printed out.
void Employee::searchInventory(std::string albumTitle)
{
    try
    {
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return;
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
void Employee::printInventory()
{
    try
    {
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return;
        }
        this->inv->printInventory(); 
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
}

// addToInventory Function:
// This function takes in an album title to add to the inventory.
// Will check to see if addition to inventory was successful, and if so
// it will output this change to the changeLog txt file.
void Employee::addToInventory(std::string albumTitle, std::string artist, float price, int numUnits)
{
    try
    {
        // Check if Inventory object is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return;
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
            ss << "/t/tAlbum Title: " << albumTitle << " Artist: " << artist << " Price: " << price << " Units Added: " << numUnits << std::endl;
            ss << std::endl;
            // Output string stream to changeLog
            std::ofstream output;
            output.open(changelogPat, std::ios::app);
            output << ss.str();
            output.close();
            return;
        }
        else
        {
            // Exit program upon failure, error text will already be printed by addToInventory function
            return;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
}

// deleteFromInventory Function:
// This function is used to delete an item from the inventory given an album title.
// Will check to see if item can be deleted from the inventory, and if it can, it will
// output the item information of the deleted item to the changelog txt file.
void Employee::deleteFromInventory(std::string albumTitle)
{
    try
    {
        // Check if Inventory object is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return;
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
            ss << "/t/tAlbum Title: " << delItem.albumName_ << " Artist: " << delItem.artistName_ << " Price: " << delItem.price_ << " Units Deleted: " << delItem.numUnits_ << std::endl;
            ss << std::endl;
            // Output string stream to changeLog txt file
            std::ofstream output;
            output.open(changelogPat, std::ios::app);
            output << ss.str();
            output.close();
            return;
        }
        else
        {
            // Exit program upon failure, error text will already be printed by addToInventory function
            return;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
}

// editArtist Function:
// This function will allow the user to take in an album title, and a new artist
// to overwrite the old artist for the album. First checks to see if the album can be found,
// and if it can, it updates the artist name for the album.
void Employee::editArtist(std::string albumTitle, std::string newArtist)
{
    try
    {
        // Check if Inventory object is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return;
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
            ss << "/t/tAlbum Title: " << albumTitle << " New Artist: " << newArtist << std::endl;
            ss << std::endl;
            // Output string stream to changeLog
            std::ofstream output;
            output.open(changelogPat, std::ios::app);
            output << ss.str();
            output.close();
            return;
        }
        else
        {
            // Exit program upon failure, error text will already be printed by addToInventory function
            return;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
}
void Employee::editPrice(std::string albumTitle, float newPrice)
{
     try
    {
        // Check if Inventory object is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return;
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
            ss << "/t/tAlbum Title: " << albumTitle << " New Price: " << newPrice << std::endl;
            ss << std::endl;
            // Output string stream to changeLog
            std::ofstream output;
            output.open(changelogPat, std::ios::app);
            output << ss.str();
            output.close();
            return;
        }
        else
        {
            // Exit program upon failure, error text will already be printed by addToInventory function
            return;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
}
void Employee::editUnits(std::string albumTitle, int newUnits)
{
     try
    {
        // Check if Inventory object is allocated
        if (this->inv == nullptr)
        {
            throw "Error: Inventory Not Set.";
            return;
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
            ss << "Action: Edit Album Artist" << std::endl;
            ss << "Details: " << std::endl;
            ss << "/t/tAlbum Title: " << albumTitle << " New Unit Count: " << newUnits << std::endl;
            ss << std::endl;
            // Output string stream to changeLog
            std::ofstream output;
            output.open(changelogPat, std::ios::app);
            output << ss.str();
            output.close();
            return;
        }
        else
        {
            // Exit program upon failure, error text will already be printed by addToInventory function
            return;
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
}

// Destructor
Employee::~Employee(){}