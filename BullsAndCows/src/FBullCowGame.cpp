#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "donkey";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) 
	{
		return EGuessStatus::Not_Isogram;
	}
 else if (false) 
	 {
	 return EGuessStatus::Not_Lowercase;
	}
 else if (Guess.length() != GetHiddenWordLength())
	{
	 return EGuessStatus::Wrong_Length;
	}
 else 
	{
	 return EGuessStatus::OK;
	}
}


// receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment turn number
	MyCurrentTry++;

	//set up a return variable
	FBullCowCount BullCowCount;
	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}
