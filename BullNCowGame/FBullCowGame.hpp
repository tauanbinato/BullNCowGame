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

class FBullCowGame{
    
public:
    FBullCowGame(); //Constructor
    
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool isGameWon() const;
    
    
    void AddCurrentTry();
    void Reset();
    bool CheckGuessValidity(FString);
    // provide a method for couting bulls & cows , and increasing try number
    
    
private:
    
    //See constructor for private initiliazation
    int32 MyCurrentTry;
    int32 MyMaxTries;
    
};


#endif /* FBullCowGame_hpp */
