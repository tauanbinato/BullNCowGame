//
//  FBullCowGame.cpp
//  BullNCowGame
//
//  Created by Tauan Binato Flores on 09/11/16.
//  Copyright © 2016 Tauan Binato Flores. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <map>
#include <stdio.h>
#include <ctype.h>
#define TMap std::map

//for Unreal
using int32 = int;


FBullCowGame::FBullCowGame(){ Reset(); }    //  default Constructor


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return (int32)MyHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameIsWon; }


int32 FBullCowGame::GetMaxTries() const
{
    TMap<int32,int32> WordLengthToMaxTries { {3,4}, {4,7}, {5,10}, {6,13} , {7,15} };
    return WordLengthToMaxTries[(int32)MyHiddenWord.length()];
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if(!IsIsogram(Guess))
    {
        return EGuessStatus::Not_Isogram;
    }
    else if(!isLowerCase(Guess))
    {
        return EGuessStatus::Not_LowerCase;
    }
    else if(Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
     return EGuessStatus::OK;
    }
}

bool FBullCowGame::IsIsogram(FString Word) const {
    
    //treat 0 and 1 letter words as isograms
    if(Word.length() <= 1){ return true; }
    
    //setup our map
    TMap<char , bool> LetterSeen;
    
    for(auto Letter : Word)    // for all letter of the word
    {
        Letter = tolower(Letter);
       
        if(LetterSeen[Letter]) //if the letter is in he map
        {
            return false; //we do not have an isogram
        }else
        {
            LetterSeen[Letter] = true;
        }
        
        
        // add the letter to the map as seen
    }
    
    return true; // for exemple in cases where /0 is entered
}

bool FBullCowGame::isLowerCase(FString Word) const{
    
    
    for(char Letter : Word)// for all letter of the word
    {
        if(!islower(Letter))
        {
            return false;
        }
        
    }
    return true;
}


void FBullCowGame::Reset()
{
    
    SetHiddenWord(MyCurrentWordLength); //Set one hidden word isogram based on our private variable.
    
    MyCurrentTry = 1;
    bGameIsWon = false;
    
    return;
}

void FBullCowGame::AddCurrentTry()
{
    MyCurrentTry++;
}


FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    
    
    FBullCowCount BullCowCount;
    AddCurrentTry();
    
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
    
    //Test if game finished!
    if(BullCowCount.Bulls == HiddenWordLength)
    {
        bGameIsWon = true;
    }
    else
    {
        bGameIsWon = false;
    }
    
    return BullCowCount;
}

void FBullCowGame::SetWordLength(int32 size)
{
    MyCurrentWordLength = size;
    return;
}

void FBullCowGame::SetHiddenWord(int32 MyHiddenWordLength)
{

    TMap<int32,FString> WordLengthToSomeWord { {3,"luz"}, {4,"unha"}, {5,"pomba"}, {6,"chaves"} , {7,"frangos"} };
    MyHiddenWord = WordLengthToSomeWord[MyCurrentWordLength];
    return;
    
}
