//
//  ex_2-29.cpp
//  Excercise 2.29
//
//  Created by Luis Miranda

//  This program prints a table of integers from 0 to 10
//  and their respective square and cubed values.
//
//

#include <iostream>

int main() {
    std::cout << "integer square  cube" << std::endl;
    
    int square;
    int cube;
    
    for (int i = 0; i<=10; i++) {
        std::cout << i << "\t\t";
        
        square = i * i;
        std::cout << square << "\t\t";
        
        cube = i * i * i;
        std::cout << cube << std::endl;
    }
}
