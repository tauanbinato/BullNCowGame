//
//  main.cpp
//  BullCowGame
//
//  Created by Tauan Binato Flores on 08/11/16.
//  Copyright © 2016 Tauan Binato Flores. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetPlayerGuess();
void SayGuess(string guess);
void PlayGame();

/* The entry point */

int main()
{
    
    PrintIntro();
    PlayGame();
    
    return 0;
}

/* Play Game */

void PlayGame()
{
    //Loop asking for guesses
    string Guess;
    constexpr int NUMBER_OF_TURNS = 5;
    for(int count = 0 ; count < NUMBER_OF_TURNS; count++){
        
        Guess = GetPlayerGuess();
        SayGuess(Guess);
        cout << endl;
    }
}

/* Repeat the Guess for the user */

void SayGuess(string guess)
{
    cout << "Your guess word was: " << guess << endl;
    return;
}

/* Get Player Guess */

string GetPlayerGuess()
{
    
    /*get a guess from the player */
    string Guess = "";
    cout << "Enter a guess word: ";
    getline(cin , Guess);
    
    return Guess;
    
}


/* Introduce the game */

void PrintIntro()
{
    
    constexpr int WORLD_LENGTH = 9;
    cout << "Welcome to Bulls and Cows, a fun word game.\n";
    cout << "Can you guess the "<< WORLD_LENGTH;
    cout << " letter isogram I'm thinking of?\n";
    
    return;
}
