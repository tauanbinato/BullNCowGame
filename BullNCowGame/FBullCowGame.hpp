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

class FBullCowGame{
    
public:
    FBullCowGame(); //Constructor
    
    
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool isGameWon() const;
    
    
    void AddCurrentTry();
    void Reset();
    bool CheckGuessValidity(std::string);

    
    
private:
    
    //See constructor for private initiliazation
    int MyCurrentTry;
    int MyMaxTries;
    
};


#endif /* FBullCowGame_hpp */
