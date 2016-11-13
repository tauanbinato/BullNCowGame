//
//  FBullCowGame.hpp
//  BullNCowGame
//
//  Created by Tauan Binato Flores on 09/11/16.
//  Copyright © 2016 Tauan Binato Flores. All rights reserved.
//
// * The game logic (no view code or direct user interaction)     *
// * The game is a simple guess the word game based on Mastermind *

#pragma once

#include <stdio.h>
#include <string>


//to make syntax Unreal friendly
using FString = std::string;
using int32 = int;


enum class EGuessStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_LowerCase
    
};


typedef struct FBullCowCount
{
    
    int32 Bulls = 0;
    int32 Cows = 0;
    
}BullCowCount;



/* Class Declaration */

class FBullCowGame{
    
public:
    
    FBullCowGame(); //Constructor
    
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    
    
    bool isGameWon() const;
    
    EGuessStatus CheckGuessValidity(FString) const;
    
    void AddCurrentTry();
    void Reset();
    
    void SetWordLength(int32);
    
    FBullCowCount SubmitValidGuess(FString);
    
private:
    
    //See constructor for private initiliazation
    int32 MyCurrentTry;
    int32 MyCurrentWordLength;
    FString MyHiddenWord;
    bool bGameIsWon;
    
    bool IsIsogram(FString) const;
    bool isLowerCase(FString) const;

    void SetHiddenWord(int32);
};


/* FBullCowGame_hpp */
