//
//  FBullCowGame.cpp
//  BullNCowGame
//
//  Created by Tauan Binato Flores on 09/11/16.
//  Copyright © 2016 Tauan Binato Flores. All rights reserved.
//

#include "FBullCowGame.hpp"

int FBullCowGame::GetMaxTries() const{ return MyMaxTries; }

int FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }


void FBullCowGame::Reset()
{
    return;
}

bool FBullCowGame::isGameWon()
{
    
    return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
    return false;
}

void FBullCowGame::AddCurrentTry()
{
    MyCurrentTry++;
}
