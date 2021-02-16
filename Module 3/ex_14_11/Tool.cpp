//
//  Tool.cpp
//  ex_14_11
//
//  Created by Luis Miranda
//
//  Models the record for one indivudal tool. Each record contains a record number,
//  a name for the item, a quanitity, and a cost.

#include "Tool.h"
#include <iostream>
#include <string>

// Constructor
Tool::Tool(int number, const std::string& name, int quantity, double cost)
: recordNumber(number), itemQuantity(quantity), itemCost(cost){
    setItemName(name);
}

// Getters

int Tool::getRecordNumber() const{
    return recordNumber;
}

std::string Tool::getItemName() const{
    return itemName;
}

int Tool::getItemQuantitiy() const{
    return itemQuantity;
}

double Tool::getItemCost() const{
    return itemCost;
}

// Setters

void Tool::setRecordNumber(int number){
    recordNumber = number;
}

void Tool::setItemName(const std::string& name){
    size_t length{ name.size() };
    length = length < 30 ? length : 29;
    name.copy(itemName, length);
    itemName[length] = '\0';
}

void Tool::setQuantity(int quantity){
    itemQuantity = quantity;
}

void Tool::setCost(double cost){
    itemCost = cost;
}
