//
//  FBullCowGame.cpp
//  BullNCowGame
//
//  Created by Tauan Binato Flores on 09/11/16.
//  Copyright © 2016 Tauan Binato Flores. All rights reserved.
//

#include "FBullCowGame.hpp"

using int32 = int;

FBullCowGame::FBullCowGame(){ Reset(); }    // Constructor

int32 FBullCowGame::GetMaxTries() const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::isGameWon() const
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

BullCowCount FBullCowGame::SubmitGuess(FString)
{
    
    AddCurrentTry();
    BullCowCount bullCowCount;
    
    return bullCowCount;
}
