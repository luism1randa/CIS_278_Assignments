//
//  ex_2-19.cpp
//  Excercise 2.19
//
//  Created by Luis Miranda

//  This program takes three numbers from the keyboard then
//  calculates the sum, average, product, smallest, and largest
//  values and prints them.
//

#include <iostream>

int main() {
        
    int number1;
    int number2;
    int number3;
    
    std::cout << "Input three different integers: ";
    
    std::cin >> number1;
    std::cin >> number2;
    std::cin >> number3;
    
    int sum = number1 + number2 + number3;
    int product = number1 * number2 * number3;
    
    int avg = product/sum;
    
    int smallest;
    
    if (number1 <= number2 && number1 <= number3) {
        smallest = number1;
    } else if (number2 <= number1 && number2 <= number3){
        smallest = number2;
    } else {
        smallest = number3;
    }
    
    int largest;
    
    if (number1 >= number2 && number1 >= number3) {
        largest = number1;
    } else if (number2 >= number1 && number2 >= number3){
        largest = number2;
    } else {
        largest = number3;
    }
        
    std::cout << "Sum is " << sum << std::endl;
    std::cout << "Average is " << avg << std::endl;
    std::cout << "Product is " << product << std::endl;
    std::cout << "Smallest is " << smallest << std::endl;
    std::cout << "Largest is " << largest << std::endl;
}
