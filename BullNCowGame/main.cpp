
//  Created by Tauan Binato Flores on 08/11/16.
//  Copyright © 2016 Tauan Binato Flores. All rights reserved.
//.

/* This is the console executable , that makes use of the BullCow Class.
   This acts as the view in a MVC pattern , and is responsible for all user interaction.
   For game logic see the FBullCowgame class.*/

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetPlayerGuess();
void SayGuess(FText guess);
void PlayGame();
bool AskToPlayAgain();
void GameLoop();

FBullCowGame BCGame; // Instantiante a new game.

/* The entry point */

int main()
{
    
    GameLoop();
    return 0;
}


/* Game Loop */

void GameLoop()
{
    bool isPlaying = true;
    
    do {
    PrintIntro();
    PlayGame();
    isPlaying = AskToPlayAgain();
    } while(isPlaying);
    
    return;
}

/* Ask To Play Again */
bool AskToPlayAgain()
{
    std::cout << "Do you wanna play again?(y/n) ";
    FText Response = "";
    getline(std::cin , Response);
    
    if(Response[0] == 'y' || Response[0] == 'Y'){
        return true;
    }
    
    return false;
}



/* Play Game */

void PlayGame()
{
    
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    //Loop asking for guesses

    for(int32 count = 0 ; count < MaxTries; count++){
        
        FText Guess = GetPlayerGuess(); // TODO make loop checking valid
        
        // Submit valid guess to the game
        // Print number of bulls and cows
        
        SayGuess(Guess);
        std::cout << std::endl;
    }
    
    // TODO summarise game
    
    return;
}

/* Repeat the Guess for the user */

void SayGuess(FText guess)
{
    std::cout << "Your guess word was: " << guess << std::endl;
    return;
}

/* Get Player Guess */

FText GetPlayerGuess()
{
    
    int32 CurrentTry = BCGame.GetCurrentTry();
    
    /*get a guess from the player */
    FText Guess = "";
    std::cout << "Try " << CurrentTry << ". Enter a guess word: ";
    std::getline(std::cin , Guess);
    
    BCGame.AddCurrentTry();
    
    return Guess;
    
}


/* Introduce the game */

void PrintIntro()
{
    std::cout << std::endl;
    constexpr int32 WORLD_LENGTH = 9;
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the "<< WORLD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    
    return;
}
