/*
 a3_1.cpp
 loops
 Fundamentals in Programming C++
 Instructor David Lee Harden
 Written by Stacey Rivet Beck on 2/3/17
 
 This program is a number guessing game between the computer and
 the user.  The user thinks of a number and the computer has to 
 guess the number. The computer guesses the midpoint of the number
 range and the user needs to indicate if the number is higher or 
 lower than the guess.  If the guess is correct the program responds
 appropriately and asks the computer to play again, otherwise, the 
 program quits.
 
*/

#include <iostream>
using namespace std;

//function prototypes
void playOneGame();
void getUserToGuess(int, char &);
int getMidpoint (int, int);


int main()
{
    char response;
    cout << "Ready to play? (y/n): ";
    cin >> response;
    
    while (response == 'y')
    {
        playOneGame();
        cout << "Great! Do you want to play again? (y/n): ";
        cin >> response;

    }
    
}

void playOneGame ()
{
    bool fStop = false;
    char result = 0;
    int low = 0;
    int high = 100;
    cout << "Think of a number between 1 and 100" << endl;
    
    do
    {
        int guess = getMidpoint(low, high);
        
        getUserToGuess (guess, result);
    
        if (result == 'h')
        {
            low = guess;       // sets the guess as lowest number in range
            getMidpoint (low, high);
        
        }
        
        if (result == 'l')   // sets the guess as highest number in range
        {
            high = guess;
            getMidpoint (low, high);
        }
        
        if (result == 'c')
        {
            fStop = true;
        }
    
    }
    while (!fStop);
    
}


void getUserToGuess (int guess, char& result)
{

    cout << "Is it " << guess << " (h/l/c)? ";
    cin >> result;
    
}

// calculates the midpoint between two numbers in a range
int getMidpoint ( int low, int high)
{
    return (high + low)/2;
}
