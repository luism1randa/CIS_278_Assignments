//
//  ex_6-57.cpp
//  Excercise 6.57
//
//  Created by Luis Miranda
//
//  This program creates a multiplication question with two random
//  integers between 0 and 9. The user can answer the question and
//  recieve feedback. If the user is wrong they can try again, if
//  the user is correct they get a new question.

#include <iostream>
#include <cstdlib>      // contains rand() and srand()
using namespace std;

void askQuestion(int, int);

int main() {
    
    // Generate a random seed to randomize the
    // random number generator
    srand( static_cast<unsigned int> (time(0)) );
    
    // Generate two random integers between 0 and 9
    int numOne = rand() % 10;
    int numTwo = rand() % 10;
    
    askQuestion(numOne, numTwo);
    
}

void askQuestion(int numOne, int numTwo){
    /*
       This function takes two randomly generated integers and asks
       a multiplication question. It checks the answer and asks
       a new question if the user is correct or asks the user to try
       again if they are incorrect. The function does these tasks
       by recursing into itself.
    
       @param numOne (int) - a randomly generated integer
       @param numTwo (int) - a randomly generated integer
    */
        
    // Prompt user for answer
    cout << "How much is " << numOne << " times " << numTwo << "?" << endl;
    int userAnswer;
    cin >> userAnswer;
    
    int correctAnswer = numOne * numTwo;
    
    if (userAnswer == correctAnswer){
        cout << "Very Good!\n" << endl;
        int newNumOne = rand() % 10;
        int newNumTwo = rand() % 10;
        askQuestion(newNumOne, newNumTwo);
    } else {
        cout << "No. Please try again.\n" << endl;
        askQuestion(numOne, numTwo);
    }
}
