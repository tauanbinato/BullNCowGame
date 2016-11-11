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

class FBullCowGame{
    
public:
    
    void Reset();
    int GetMaxTries();
    
    
private:
    
    int MyCurrentTry;
    int MyMaxTries;
    
};


#endif /* FBullCowGame_hpp */
