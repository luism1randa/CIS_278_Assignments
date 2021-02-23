//
//  ex_6-58.cpp
//  Excercise 6.58
//
//  Created by Luis Miranda
//
//  This program creates a multiplication question with two random
//  integers between 0 and 9. The user can answer the question and
//  recieve feedback. If the user is wrong they can try again, if
//  the user is correct they get a new question.
//
//  Each time the user enters an answer they are given randomly
//  generated feedback chosen from 4 options if they are correct
//  and 4 seperate options if they are incorrect.

#include <iostream>
#include <cstdlib>      // contains rand() and srand()
using namespace std;

void askQuestion(int, int);
void giveFeedback(bool);

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
    bool answerIsCorrect;
    
    if (userAnswer == correctAnswer){
        // Display feedback for correct answer
        answerIsCorrect = true;
        giveFeedback(answerIsCorrect);
        
        // Generate new integers and ask new question
        int newNumOne = rand() % 10;
        int newNumTwo = rand() % 10;
        askQuestion(newNumOne, newNumTwo);
    } else {
        // Display feedback for incorrect answer
        answerIsCorrect = false;
        giveFeedback(answerIsCorrect);
        
        // Ask the same question again
        askQuestion(numOne, numTwo);
    }
}

void giveFeedback(bool answerIsCorrect){
    /*
     This function displays one of multiple feedback options
     which depend on if the user was correct or incorrect.
     
     @param answerIsCorrect (bool) - True if the user was correct, false if the
                                     the user was incorrect.
     */
    
    // Generate a random integer between 0 and 3
    int response = rand() % 4;
    
    if (answerIsCorrect) {
        switch (response) {
            case 0:
                cout << "Very good!\n" << endl;
                break;
            case 1:
                cout << "Excellent!\n" << endl;
                break;
            case 2:
                cout << "Nice Work!\n" << endl;
                break;
            case 3:
                cout << "Keep up the good work!\n" << endl;
                break;
        }
    } else {
        switch (response) {
            case 0:
                cout << "No. Please try again\n" << endl;
                break;
            case 1:
                cout << "Wrong. Try once more.\n" << endl;
                break;
            case 2:
                cout << "Don't give up!\n" << endl;
                break;
            case 3:
                cout << "No. Keep trying\n" << endl;
                break;
        }
    }
    
}
