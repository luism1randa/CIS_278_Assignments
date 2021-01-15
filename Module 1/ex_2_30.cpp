//
//  ex_2-30.cpp
//  Excercise 2.30
//
//  Created by Luis Miranda

//  This program takes the users weight and height to calculate the
//  user's BMI. It also compares it to the Department of Health and
//  Human Services BMI ranges.
//
//  The forumla used to calculate the BMI is:
//
//           weight (lbs) * 703
//  BMI = -------------------------
//        height (in) * height (in)
//

#include <iostream>

int main() {
    
    int weight;
    std::cout << "What is your weight in pounds: ";
    std::cin >> weight;
    
    int height;
    std::cout << "What is your height in inches: ";
    std::cin >> height;
    
    int bmi = (weight * 703)/(height * height);
    
    std::cout << "\nYour BMI is " << bmi << "\n" << std::endl;
    
    std::cout << "BMI VALUES" << std::endl;
    std::cout << "Underweight: less than 18.5" << std::endl;
    std::cout << "Normal: between 18.5 and 24.9" << std::endl;
    std::cout << "Overweight: between 25 and 29.9" << std::endl;
    std::cout << "Obese: 30 or greater" << std::endl;

}
