// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetUpGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (GameOver)
    {
        ClearScreen();
        SetUpGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}
void UBullCowCartridge::SetUpGame() // Set up
{
    GameOver = false;
    Lives = 4;
    HiddenWords = TEXT("NGU");
    PrintLine(TEXT("Now, Let's guess!!!"));
    PrintLine(TEXT("You have %i lives left"), Lives);
    PrintLine(TEXT("Hint: The Answer have %i words!"), HiddenWords.Len());
}
void UBullCowCartridge::EndPlay() // Game Over
{
    GameOver = true;
    PrintLine(TEXT("Press enter to play again"));
}

void UBullCowCartridge::ProcessGuess(Fstring Guess) //
{
    if (Guess == HiddenWords)
    {
        PrintLine(TEXT("Your answer is true: %s"), *HiddenWords);
        PrintLine(TEXT("U so smart!- Congratulations"));
        EndPlay();
    }
    else
    {
        PrintLine(TEXT("Your answer is false: %s"), *Guess);
        Lives--;
        PrintLine(TEXT("You have %i lives left"), Lives);
        if (Lives == 0)
            EndPlay();
    }
}