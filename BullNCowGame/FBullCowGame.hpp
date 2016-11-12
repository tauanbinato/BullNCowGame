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

typedef struct FBullCowCount
{
    
    int32 Bulls = 0;
    int32 Cows = 0;
    
}BullCowCount;


class FBullCowGame{
    
public:
    
    FBullCowGame(); //Constructor
    
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool isGameWon() const;
    bool CheckGuessValidity(FString) const;
    
    
    void AddCurrentTry();
    void Reset();
    
    FBullCowCount SubmitGuess(FString);
    
private:
    
    //See constructor for private initiliazation
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    
};


#endif /* FBullCowGame_hpp */
