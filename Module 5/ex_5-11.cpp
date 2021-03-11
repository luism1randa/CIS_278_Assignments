//
//  ex_5-11.cpp
//  Exercise 5.11
//
//  Created by Luis Miranda
//
//  This program allows a user to input a series of integers and finds the
//  smallest value.

#include <iostream>

int main() {
    
    std::cout << "This program finds the smallest integer in a list.\n";
    std::cout << "How many integers would you like to enter?\n";
    
    int numberOfInputs;
    std::cin >> numberOfInputs;
    
    std::cout << "Enter your first integer: ";
    
    int smallestInt;
    std::cin >> smallestInt;
    
    int nextInt;
    
    for (int input = 1; input < numberOfInputs; input++) {
        std::cout << "Enter your next integer: ";
        std::cin >> nextInt;
        
        if (nextInt < smallestInt) {
            smallestInt = nextInt;
        }
    }
    
    std::cout << "The smallest integer you entered was " << smallestInt << std::endl;
}
