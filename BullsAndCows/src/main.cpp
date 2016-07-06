/* This is the console executable that makes use of the BullCowClass
This acts as the view in a MVC patterns and is responsible for all
user interaction.  For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

					 // entry point for app
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}


// introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 i = 1; i <= MaxTries; i++)
	{
		FText Guess = GetGuess(); //TODO check for validity

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

	// print # of bulls and cows
		std::cout << "Bulls == " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}

	// TODO summarize game
}


FText GetGuess()
{
	// get guess from player and repeat it back
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? y/n ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
	std::cout << std::endl;

	return false;
}
