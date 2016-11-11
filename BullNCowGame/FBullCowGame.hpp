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
    
    void Reset();
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool isGameWon();
    void AddCurrentTry();
    bool CheckGuessValidity(std::string);

    
    
private:
    
    int MyCurrentTry = 1;
    int MyMaxTries = 5;
    
};


#endif /* FBullCowGame_hpp */
