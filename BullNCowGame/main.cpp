
//  Created by Tauan Binato Flores on 08/11/16.
//  Copyright © 2016 Tauan Binato Flores. All rights reserved.
//.

/* This is the console executable , that makes use of the BullCow Class.
   This acts as the view in a MVC pattern , and is responsible for all user interaction.
   For game logic see the FBullCowgame class.*/

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"
#define MAX_WORD_LENGTH 8
#define MIN_WORD_LENGTH 3


//to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// fuction prototypes as outside a class
void PrintIntro();
void PrintIntro_2();
FText GetPlayerGuess();
void SayGuess(FBullCowCount BullCowCount);
void PlayGame();
bool AskToPlayAgain();
void GameLoop();
void PrintGameSummary();
void SelectNumberOfLetters();


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
    SelectNumberOfLetters();
    BCGame.Reset();
    PrintIntro_2();
        
    PlayGame();
    isPlaying = AskToPlayAgain();
    } while(isPlaying);
    
    return;
}

/* Ask To Play Again */
bool AskToPlayAgain()
{
    std::cout << "Do you wanna play again with the same hidden word?(y/n) ";
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

    while(!BCGame.isGameWon() && BCGame.GetCurrentTry() <= MaxTries){
        
        FText Guess = GetPlayerGuess();
        
        // Submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
       
        SayGuess(BullCowCount);
        
        std::cout << std::endl;
    }
    
    PrintGameSummary();
    
    
    return;
}

/* Select Number of letters */

void SelectNumberOfLetters()
{
    int32 wordLengthSelected;
    
    do{
    std::cout << "Please enter the word length between 3 and 7 that you want me to think: ";
    std::cin >>  wordLengthSelected;
    
        if(wordLengthSelected >= MAX_WORD_LENGTH || wordLengthSelected < MIN_WORD_LENGTH)
        {
            std::cout << "\nYou need to choose a length less than 8 and greater than 2.\n\n";
        }
    
    }while((wordLengthSelected >= MAX_WORD_LENGTH) || wordLengthSelected < MIN_WORD_LENGTH);

    BCGame.SetWordLength(wordLengthSelected);
   
    return;
}

/* Print the summary */

void PrintGameSummary()
{
    if(BCGame.isGameWon())
    {
        std::cout << "Congrats! You WIN the Game! :D\n" << std::endl;
        return;
    }
    else if (!BCGame.isGameWon())
    {
        std::cout << "GAME OVER! You LOST the Game! :(\n" << std::endl;
        return;
    }
    
    
    return;
}

/* Repeat the Guess for the user */

void SayGuess(FBullCowCount BullCowCount)
{
    std::cout << "Bulls " << BullCowCount.Bulls;
    std::cout << ". Cows " << BullCowCount.Cows << std::endl;
    return;
}

/* Get Player Guess */

FText GetPlayerGuess()
{
    
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    FText Guess = "";
    
    do {
        /*get a guess from the player */
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << " of "<< BCGame.GetMaxTries() << ". Enter a guess word: ";
        std::getline(std::cin , Guess);
        //std::cout << "aqui " << Guess;
    
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status) {
        case EGuessStatus::Wrong_Length:
            std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
            break;
            
        case EGuessStatus::Not_LowerCase:
            std::cout << "Please use only lower case letters!\n";
            break;
            
        case EGuessStatus::Not_Isogram:
            std::cout << "Please enter a word without repeating letters!\n";
            break;
            
        default:
            // assume the guess is valid
                break;
        }
        
        std::cout << std::endl;
        
    } while(Status != EGuessStatus::OK);

    return Guess;
}


/* Introduce the game */

void PrintIntro()
{
    std::cout << std::endl;
    std::cout << "\nWelcome to Bulls and Cows, a fun word game.\n";
    std::cout << std::endl;
    std::cout << "          } __ {       _____              " << std::endl;
    std::cout << "          (O  O)       (o o)              " << std::endl;
    std::cout << "    /------\\  /         \\ /--------       " << std::endl;
    std::cout << "   /|      |OO           -|        |\\    " << std::endl;
    std::cout << "  / | BULL |              |  COW   | \\   " << std::endl;
    std::cout << " /  |      |              |        |  \\  " << std::endl;
    std::cout << "*   |-,----|              |-(    )-|   *  " << std::endl;
    std::cout << "    X      X              x  ''''  x      " << std::endl;
    std::cout << "                                          " << std::endl;
    
    
    return;
}

void PrintIntro_2(){
    
    std::cout << "Can you guess the "<< BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n\n";
    return;
}
