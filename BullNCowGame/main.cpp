//
//  main.cpp
//  BullCowGame
//
//  Created by Tauan Binato Flores on 08/11/16.
//  Copyright © 2016 Tauan Binato Flores. All rights reserved.
//.

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"


void PrintIntro();
std::string GetPlayerGuess();
void SayGuess(std::string guess);
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
    std::string Response = "";
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
    int MaxTries = BCGame.GetMaxTries();
    
    //Loop asking for guesses

    for(int count = 0 ; count < MaxTries; count++){
        
        std::string Guess = GetPlayerGuess();
        SayGuess(Guess);
        std::cout << std::endl;
    }
    return;
}

/* Repeat the Guess for the user */

void SayGuess(std::string guess)
{
    std::cout << "Your guess word was: " << guess << std::endl;
    return;
}

/* Get Player Guess */

std::string GetPlayerGuess()
{
    
    int CurrentTry = BCGame.GetCurrentTry();
    
    /*get a guess from the player */
    std::string Guess = "";
    std::cout << "Try " << CurrentTry << ". Enter a guess word: ";
    std::getline(std::cin , Guess);
    
    BCGame.AddCurrentTry();
    
    return Guess;
    
}


/* Introduce the game */

void PrintIntro()
{
    std::cout << std::endl;
    constexpr int WORLD_LENGTH = 9;
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the "<< WORLD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    
    return;
}
