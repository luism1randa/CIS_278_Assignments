//
//  ex_4-15.cpp
//  Excercise 4.15
//
//  Created by Luis Miranda

//  This program uses a while loop to input a salesman's sales for a week and calculates
//  their earnings.
//
//  A salesman recieves $200 a week + 9% of their sales that week.
//

#include <iostream>
#include <iomanip>

int main() {

    // Set double values to print with two decimal points
    std::cout << std::setprecision(2) << std::fixed;
    
    const double base = 200;
    double sales; // Will serve as sentinal
    double salary;
    
    std::cout << "Enter sales in dollars (-1 to end): ";
    std::cin >> sales;
    
    while (sales != -1) {
        
        salary = base + (sales * 0.09);
        std::cout << "Salary is: $" << salary << std::endl << std::endl;
        
        std::cout << "Enter sales in dollars (-1 to end): ";
        std::cin >> sales;
    }
}
