//
//  FBullCowGame.cpp
//  BullNCowGame
//
//  Created by Tauan Binato Flores on 09/11/16.
//  Copyright © 2016 Tauan Binato Flores. All rights reserved.
//

#include "FBullCowGame.hpp"

void FBullCowGame::Reset()
{
    return;
}

int FBullCowGame::GetMaxTries()
{
    return MyMaxTries;
}

bool FBullCowGame::isGameWon()
{
    
    return false;
}

int FBullCowGame::GetCurrentTry()
{
    return MyCurrentTry;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
    return false;
}

void FBullCowGame::AddCurrentTry()
{
    MyCurrentTry++;
}
