//
//  ex_14_11.cpp
//  Exercise 14.11
//
//  Created by Luis Miranda
//
//  This file keeps track of hardware inventory records using a randomized access file.
//  The user uses a menu to choose whether they want to create a new record, list existing
//  records, modify a record, or delete a record. Each record contains an item's record #,
//  the item's name, a quanitity, and a cost.
//

#include <iostream> // Contains cin, cout, and cerr
#include <iomanip> // Allows formatting decimal precision and text
#include <fstream> // Allows creating, reading, and writing files
#include <string>
#include "Tool.h" // Allows creation and manipulation of records for individual tools

// Prototypes

// Opening and creating files
std::fstream openFile(std::string fileName);
void initFile(std::string fileName, int numberOfRecords, Tool blankRecord);

// Modifying records
void writeNewRecord(Tool newRecord, std::string fileName);
void modifyExistingRecord(Tool newRecord, std::string fileName);
void deleteItem(Tool blankRecord, std::string fileName);

// Reading records
void readFile(std::string fileName);
void outputLine(std::ostream &output, const Tool &record);
bool recordDoesNotExist(std::string fileName, int recordNumber);


int main() {
    
    const std::string fileName = "inventory.dat";
    
    // Initialize a randomized access file with 100 blank records
    Tool blankRecord;
    const int numberOfRecords = 100;
    initFile(fileName, numberOfRecords, blankRecord);
    
    Tool newRecord;
    
    const int createRecord = 1;
    const int listAllRecords = 2;
    const int modifyRecord = 3;
    const int deleteRecord = 4;
    const int exit = 5;
    
    int menuSelection;
    
    do {
        std::cout << "\n+------------------------+\n";
        std::cout << "| 1. Create a new record |\n";
        std::cout << "| 2. List all records    |\n";
        std::cout << "| 3. Modify a record     |\n";
        std::cout << "| 4. Delete a record     |\n";
        std::cout << "| 5. Exit                |\n";
        std::cout << "+------------------------+\n";
        std::cout << "Please select a valid menu item: ";
        std::cin >> menuSelection;
        
        switch (menuSelection) {
            case createRecord:
                writeNewRecord(newRecord, fileName);
                break;
            case listAllRecords:
                readFile(fileName);
                break;
            case modifyRecord:
                modifyExistingRecord(newRecord, fileName);
                break;
            case deleteRecord:
                deleteItem(blankRecord, fileName);
                break;
            case exit:
                break;
            default:
                std::cout << "\nInvalid selection. Try again.\n";
                break;
        }
    } while (menuSelection != exit);
    
}


//  Opens or creates a new randomized access file.
//
//  @ fileName - the name of the file to be opened/created
//  @ return - the object representing the file
std::fstream openFile(std::string fileName){
    // Create a random access file
    std::fstream file(fileName, std::ios::in | std::ios::out | std::ios::binary);
    
    // Exit program if unable to create file
    if (!file) {
        std::cerr << "File could not be opened" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return file;
}


//  Initializes an empty file to 100 blank records. Each record contains a
//  record #, item name, item quantity, and item cost.
//
//  @ fileName - the name of the file
//  @ numberOfRecords - the number of blank records to be created
//  @ blankRecord - a template of a blank/default record
void initFile(std::string fileName, int numberOfRecords, Tool blankRecord){
    
    std::fstream file = openFile(fileName);
    
    // Create blank records to the file
    for (int record = 0; record < numberOfRecords; record++) {
        file.write(reinterpret_cast<const char *>(&blankRecord), sizeof(Tool));
    }
    
    file.close();
}


//  Writes a single record to the randomized access file in the location
//  corresponding to the record number provided.
//
//  @ newRecord - a template record to be modifed and written to the file
//  @ fileName - the name of the file to be written to
void writeNewRecord(Tool newRecord, std::string fileName){
    
    std::fstream file = openFile(fileName);
    
    int recordNumber;
    std::string itemName;
    int quantity;
    double cost;
    
    std::cout << "Enter a record # (1 to 100, 0 to quit)\n";
    std::cin >> recordNumber;
    
    // Write a new record to file
    while (recordNumber > 0 && recordNumber <= 100) {
        
        // Prompt for item details
        std::cout << "Enter an item name: ";
        std::cin >> itemName;
        std::cout << "Enter a quantity: ";
        std::cin >> quantity;
        std::cout << "Enter a cost: ";
        std::cin >> cost;
        
        // Set item details
        newRecord.setRecordNumber(recordNumber);
        newRecord.setItemName(itemName);
        newRecord.setQuantity(quantity);
        newRecord.setCost(cost);
        
        // Calculate the byte location where the new record should go and
        // position the put pointer there
        
        // Calculate Record Starting Location
        // - start = Record number. Subtract 1 because the records start at 0
        // Calculate Record Size
        // - Multiply by the size of Tool to calculate how big record should be
        file.seekp( (newRecord.getRecordNumber() - 1) * sizeof(Tool) );
        
        // Overwrite the record with the newly input record
        file.write( reinterpret_cast<const char *>(&newRecord), sizeof(Tool) );
        
        std::cout << "Enter a new record # (or 0 to quit)\n";
        std::cin >> recordNumber;
        
    }
    
    file.close();
}

//  Modifies an individual record in a file
//
//  @ newRecord - a template of a blank/default record
//  @ fileName - the name of the file to be modified
void modifyExistingRecord(Tool newRecord, std::string fileName){
    
    std::fstream file = openFile(fileName);
    
    int recordNumber;
    std::string itemName;
    int quantity;
    double cost;
    
    std::cout << "Which record would you like to modify? (1 to 100, 0 to quit)\n";
    std::cin >> recordNumber;
        
    // Write a new record to file
    while (recordNumber > 0 && recordNumber <= 100) {
        
        while (recordDoesNotExist(fileName, recordNumber)) {
            std::cout << "Record does not exist.\n";
            std::cout << "Which record would you like to modify? (1 to 100, 0 to quit)\n";
            std::cin >> recordNumber;
        }
        
        // Delete existing record before creating a new one
        file.seekp( (recordNumber - 1) * sizeof(Tool) );
        file.write( reinterpret_cast<const char *>(&newRecord), sizeof(Tool) );
                
        // Prompt for item details
        std::cout << "Enter a new record number: ";
        std::cin >> recordNumber;
        std::cout << "Enter a new item name: ";
        std::cin >> itemName;
        std::cout << "Enter a new quantity: ";
        std::cin >> quantity;
        std::cout << "Enter a new cost: ";
        std::cin >> cost;
        
        // Set item details
        newRecord.setRecordNumber(recordNumber);
        newRecord.setItemName(itemName);
        newRecord.setQuantity(quantity);
        newRecord.setCost(cost);
        
        // Calculate the byte location where the new record should go and
        // position the put pointer there
        
        // Calculate Record Starting Location
        // - start = Record number. Subtract 1 because the records start at 0
        // Calculate Record Size
        // - Multiply by the size of Tool to calculate how big record should be
        file.seekp( (newRecord.getRecordNumber() - 1) * sizeof(Tool) );
        
        // Overwrite the record with the newly input record
        file.write( reinterpret_cast<const char *>(&newRecord), sizeof(Tool) );
        
        std::cout << "Enter another record # to modify (or 0 to quit)\n";
        std::cin >> recordNumber;
        
    }
    
    file.close();
}

//  Deletes an individual record in a file
//
//  @ blankRecord - a template of a blank/default record
//  @ fileName - the name of the file to be modified
void deleteItem(Tool blankRecord, std::string fileName){
    
    std::fstream file = openFile(fileName);
    
    int recordNumber;
    const int exit = 0;
    
    std::cout << "Which record # would you like to delete? (1-100, 0 to cancel)\n";
    std::cin >> recordNumber;
    
    while (recordNumber < 0 || recordNumber > 100) {
        std::cout << "\nInvalid record number.\n";
        std::cout << "Which record # would you like to delete? (1-100, 0 to cancel)\n";
        std::cin >> recordNumber;
    }
    
    if (recordNumber != exit) {
        // Calculate the byte location where the old record should be deleted and
        // position the put pointer there
        
        // Calculate Record Starting Location
        // - start = Record number. Subtract 1 because the records start at 0
        // Calculate Record Size
        // - Multiply by the size of Tool to calculate how big the record is
        file.seekp( (recordNumber - 1) * sizeof(Tool) );
        
        // Overwrite existing record with blank record
        file.write( reinterpret_cast<const char *>(&blankRecord), sizeof(Tool) );
        
        std::cout << "Record #" << recordNumber << " succesfully deleted.\n";
    }
    
    file.close();
}


//  Reads and displays all records in a file
//
//  @ fileName - the name of the file to read
void readFile(std::string fileName){
    
    std::fstream file = openFile(fileName);
    
    // Output column heads
    std::cout << "\n+------------------------------------------------+\n";
    std::cout << std::left;
    std::cout << std::setw(11) << "| Record # ";
    std::cout << std::setw(18) << "| Tool name";
    std::cout << std::setw(11) << "| Quantity";
    std::cout << std::setw(6) << "|  Cost  |" << std::endl;
    std::cout << "+------------------------------------------------+\n";

    // Create container for record being read
    Tool record;
    
    // Get first record
    file.read( reinterpret_cast<char *>(&record), sizeof(Tool) );
    
    // Keep looking through file until end of file is reached
    while (file && !file.eof() ) {
        
        // Display the record
        if (record.getRecordNumber() != 0) {
            outputLine(std::cout, record);
        }
        
        // Get next record
        file.read( reinterpret_cast<char *>(&record), sizeof(Tool) );
    }
    
    file.close();
}


//  Reads and displays the contents of an individual record
//
//  @ &output - reference to device the text will be output to
//  @ &record - reference the individual record being read
void outputLine(std::ostream &output, const Tool &record){
    output << std::left << "  " << std::setw(9) << record.getRecordNumber();
    output << "  " << std::setw(16) << record.getItemName();
    output << "  " << std::setw(9) << record.getItemQuantitiy();
    output << "  " << std::setprecision(2) << std::right << std::fixed << std::setw(7) << record.getItemCost() << std::endl;
}


//  Checks if a provided record number already exists or not
//
//  @ fileName - the name of the file to be checked
//  @ recordNumber - the record number to look for
//  @ return - true: record does not exist, false: record does exist
bool recordDoesNotExist(std::string fileName, int recordNumber){
        
    std::fstream file = openFile(fileName);
    
    // Create container for record being read
    Tool record;
    
    // Get first record
    file.read( reinterpret_cast<char *>(&record), sizeof(Tool) );
    
    // Keep looking through file until end of file is reached
    while (file && !file.eof() ) {
        
        // Display the record
        if (record.getRecordNumber() == recordNumber) {
            file.close();
            return false; // Record exists
        }
        
        // Get next record
        file.read( reinterpret_cast<char *>(&record), sizeof(Tool) );
    }
    
    file.close();
    return true; // Record does not exist
}
