//
//  ex_3_17.cpp
//  Excercise 3.17
//
//  Created by Luis Miranda

//  This program prints out all the ASCII values from 33 to 126 in
//  decimal, octal, hexadecimal, anc character forms into a table.
//

#include <iostream>
#include <iomanip> // Includes conversions to oct and hex

int main() {
    
    // Table header
    std::cout << "         ASCII Values        " << std::endl;
    std::cout << "+---------------------------+" << std::endl;
    std::cout << "| Dec  | Oct  | Hex  | Char |" << std::endl;
    std::cout << "+---------------------------+" << std::endl;
    
    const int itemWidth = 5;
    
    // All items are left justified. They each have a width of 5 plus 1 space of padding
    // to the left.
    for (int val = 33; val <= 126; val++) {
        
        // Start row
        std::cout << "| ";
        
        // Decimal value
        std::cout << std:: left << std::setw(itemWidth) << std::dec << val << "| ";
        
        // Octal value
        std::cout << std:: left << std::setw(itemWidth) << std::oct << val << "| ";
        
        // Hexadecimal value
        std::cout << std:: left << std::setw(itemWidth) << std::hex << val << "| ";
        
        // Char value
        std::cout << std:: left << std::setw(itemWidth) << (char)val << "| ";
        
        // End row
        std::cout << std::endl;
    }
    
    // End table
    std::cout << "+---------------------------+" << std::endl;
}
