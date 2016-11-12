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
int32 FBullCowGame::GetHiddenWordLength() const{ return (int32)MyHiddenWord.length(); }


bool FBullCowGame::isGameWon() const
{
    
    return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) const
{
    return false;
}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "ant";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    return;
}

void FBullCowGame::AddCurrentTry()
{
    MyCurrentTry++;
}


FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    
    
    FBullCowCount BullCowCount;
    
    int32 HiddenWordLength = (int32)MyHiddenWord.length();
    for(int32 MHWChar = 0 ; MHWChar < HiddenWordLength ; MHWChar++)
    {
        
        for(int32 GChar = 0 ; GChar < HiddenWordLength ; GChar++)
        {
            
            if(Guess[GChar] == MyHiddenWord[MHWChar])
            {
                if(MHWChar == GChar)
                {
                    BullCowCount.Bulls++;
                }else
                {
                    BullCowCount.Cows++;
                }
            }
            
        }
        
    }
    
    
    return BullCowCount;
}
