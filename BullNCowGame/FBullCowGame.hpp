//
//  FBullCowGame.hpp
//  BullNCowGame
//
//  Created by Tauan Binato Flores on 09/11/16.
//  Copyright © 2016 Tauan Binato Flores. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

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
    
    FBullCowCount SubmitValidGuess(FString);
    
private:
    
    //See constructor for private initiliazation
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool bGameIsWon;
    
    bool IsIsogram(FString) const;
    bool isLowerCase(FString) const;
};


#endif /* FBullCowGame_hpp */
