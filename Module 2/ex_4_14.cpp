//
//  ex_4-14.cpp
//  Excercise 4.14
//
//  Created by Luis Miranda

//  This program checks a customers credit limit given an account number.
//  It looks at the balance at the beginning of the month, totall of all
//  items charged this month, total of all credits applied this month,
//  and the allowed credit limit.
//
//  New Balance = beginning balance + charges - credits
//

#include <iostream>
#include <iomanip>

int main() {

    // Set double values to print with two decimal points
    std::cout << std::setprecision(2) << std::fixed;
    
    int acctNbr;
    
    // Account number also serves as sentinal
    std::cout << "Enter account number (or -1 to quit): ";
    std::cin >> acctNbr;
    
    double balance;
    double charges;
    double credits;
    double creditLimit;
    double newBalance;
    
    while (acctNbr != -1) {
        std::cout << "Enter beginning balance: ";
        std::cin >> balance;
        
        std::cout << "Enter total charges: ";
        std::cin >> charges;
        
        std::cout << "Enter total credits: ";
        std::cin >> credits;
        
        std::cout << "Enter credit limit: ";
        std::cin >> creditLimit;
        
        newBalance = balance + charges - credits;
        std::cout << "New balance is " << newBalance << std::endl;
        
        // If user exceeds their credit limit for the month, give
        // summary of their account
        if (newBalance > creditLimit) {
            std::cout << "Account:      " << acctNbr << std::endl;
            std::cout << "Credit limit: " << creditLimit << std::endl;
            std::cout << "Balance:      " << newBalance << std::endl;
            std::cout << "Credit Limit Exceeded." << std::endl;
        }
        
        std::cout << "\nEnter account number (or -1 to quit): ";
        std::cin >> acctNbr;
    }
}
