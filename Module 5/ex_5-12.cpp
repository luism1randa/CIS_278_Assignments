//
//  ex_5-12.cpp
//  Excercise 5.12
//
//  Created by Luis Miranda
//
//  This program finds the product of the odd integers between 1 and 15
//

#include <iostream>
using namespace std;

int main() {
    int product = 1;
    
    for (int i=0; i<15; i++) {
        
        // Determine if the number is odd
        if (i % 2 != 0) {
            product *= i;
        }
    }
    
    cout << "The product of odd numbers between 1 and 15 is: " << product << endl;
    
}
