#pragma once
#include <string>

class FBullCowGame{
public:
	FBullCowGame();

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // Todo: make more rich return value
	bool CheckGuessValidity(std::string);
	// provide a method for counting bulls and cows and incrementing turn #

// Ignore and focus on public
private:
	int MyCurrentTry;
	int MyMaxTries;

};
