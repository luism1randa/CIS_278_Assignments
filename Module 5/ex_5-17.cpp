//
//  ex_5-17.cpp
//  Excercise 5.17
//
//  Created by Luis Miranda
//
//  This program reads a pair of numbers representing a product number and
//  and the quantity sold. It then uses the following table to calculate
//  the retail value of all the products sold.
//
//     -------------------
//      Product # | Price
//     -------------------
//      Product 1 | $2.98
//      Product 2 | $4.50
//      Product 3 | $9.98
//      Product 4 | $4.49
//      Product 5 | $6.87

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double retailValue = 0;
    
    bool moreToInput = true;
    int productNum;
    int quantitySold;
    int calcOrQuit;
    
    string PROMPT_PROD_NUM = "Please enter a product number: ";
    string PROMPT_QUAN_SOLD = "Please enter the quantity sold: ";
    string PROMPT_CALC = "Enter 0 to add more products or -1 to caculate retail value";
    
    while (moreToInput) {
        cout << PROMPT_PROD_NUM;
        cin >> productNum;
        
        cout << PROMPT_QUAN_SOLD;
        cin >> quantitySold;
        
        // Update the retail value of all sold products
        switch (productNum) {
            case 1:
                retailValue += quantitySold * 2.98;
                break;
            case 2:
                retailValue += quantitySold * 4.50;
                break;
            case 3:
                retailValue += quantitySold * 9.98;
                break;
            case 4:
                retailValue += quantitySold * 4.49;
                break;
            case 5:
                retailValue += quantitySold * 6.87;
                break;
        }
        
        // Ask user if they would like to input a new product or
        // if they would like to calculate the final retail value
        cout << PROMPT_CALC << endl;
        cin >> calcOrQuit;
        
        // Stop prompting the user for new inputs if they select -1
        if (calcOrQuit == -1) {
            moreToInput = false;
        }
    }
    
    // Set doubles to print with two decimal points
    cout << setprecision(2) << fixed;
    
    cout << "Total retail of all products sold is $" << retailValue << endl;
}
