#include <iostream>
#include <string>

using namespace std;


void PrintIntro();
string GetGuessAndPrintBack();

// entry point for app
int main() 
{
	PrintIntro();

	//loop for number of turns/guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}

		return 0;
}

// introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	return;
}

string GetGuessAndPrintBack()
{
	// get guess from player and repeat it back
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	//prints back
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}
