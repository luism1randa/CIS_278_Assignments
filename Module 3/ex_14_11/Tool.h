//
//  Tool.h
//  ex_14_11
//
//  Created by Luis Miranda
//
//  Header file for the tool class.


#include <string>

class Tool {

private:
    int recordNumber;
    char itemName[30];
    int itemQuantity;
    double itemCost;
    
public:

    // Default blank constructor
    Tool(int = 0, const std::string& name = "", int = 0, double = 0);
    
    // Getters
    int getRecordNumber() const;
    std::string getItemName() const;
    int getItemQuantitiy() const;
    double getItemCost() const;
    
    // Settors
    void setRecordNumber(int);
    void setItemName(const std::string&);
    void setQuantity(int);
    void setCost(double);
    
};
