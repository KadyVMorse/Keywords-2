// Keywords2.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;



int main()
{
	// Variabls and constants
	char playAgain;
	string user;
	const int MAX_WRONG = 8;
	int numOfSims = 0;

	// Display Title of program to user
	cout << "Welcome to Keywords II!";
	// Ask the recruit to login using thier name
	cout << "\nPlease, sign in using your name.\n";
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cin >> user;
	cout << "\n\n";
	// Display an overview of what Keywords II is to the recruit 
	cout << "Greetings, " << user << ", this is a program where you must utilize your skills to guess the letters in a word in a certain amount of guesses.\n\n";
	// Display an directions to the recruit on how to use Keywords
	cout << "So, " << user << " you will get a secret word and must input a letter to check to see if it is in the word. If it is, then it will be easier to find the word. If it isn't, it will add to your incorrect guesses.";

	// Thought I would use 10 words from my favorite movie hercules
	vector<string> words;
	words.push_back("HADES");
	words.push_back("PAIN");
	words.push_back("PANIC");
	words.push_back("PHIL");
	words.push_back("TITAN");
	words.push_back("OLYMPUS");
	words.push_back("HERCULES");
	words.push_back("PEGASUS");
	words.push_back("MEGARA");
	words.push_back("ZEUS");
	// Create an int var to count the number of simulations being run starting at 1
	numOfSims++;
	do {
		// Display the simulation # is staring to the recruit. 
		cout << "This is simulation #" << numOfSims << ", " << user << ".\n\n";


		for (int goodAnswers = 0; goodAnswers < 3; goodAnswers++) {
			// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
			srand(static_cast<unsigned int>(time(0)));
			random_shuffle(words.begin(), words.end());
			const string THE_WORD = words[0];
			int wrong = 0; //number of uncorrect guesses
			string soFar(THE_WORD.size(), '-'); // Word guessed so far
			string used = ""; // Letters already guessed


			// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
				//     Tell recruit how many incorrect guesses he or she has left
				cout << "\n\nYou have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				//     Show recruit the letters he or she has guessed
				cout << "\nYou'be used the following letters:\n" << used << endl;
				//     Show player how much of the secret word he or she has guessed
				cout << "\nSo far, the word is:\n" << soFar << endl;
				//     Get recruit's next guess
				char guess;
				cout << "\n\nEnter your guess: ";
				cin >> guess;
				guess = toupper(guess); // Make uppercase since secret word is in uppercase
				//     While recruit has entered a letter that he or she has already guessed
				while (used.find(guess) != string::npos) {
					//          Get recruit ’s guess
					cout << "\nYou've already guessed that, enter anoter guess: ";
					cin >> guess;
					guess = toupper(guess);
				}
				//     Add the new guess to the group of used letters
				used += guess;
				//     If the guess is in the secret word
				if (THE_WORD.find(guess) != string::npos) {
					//          Tell the recruit the guess is correct
					cout << guess << " is in the word.\n";
					//          Update the word guessed so far with the new letter
					for (int i = 0; i < THE_WORD.length(); ++i) {
						if (THE_WORD[i] == guess) {
							soFar[i] = guess;
						}
					}
					system("cls");
				}
				//     Otherwise
				else {
					//          Tell the recruit the guess is incorrect
					cout << "Sorry, " << guess << " isn't in the word.\n";
					//          Increment the number of incorrect guesses the recruit has made
					++wrong;
				}
			}
			// If the recruit has made too many incorrect guesses
			if (wrong == MAX_WRONG) {
				//     Tell the recruit that he or she has failed the Keywords II course.
				cout << "\nSorry, " << user << ", you ran out of guesses.";
			}
			// Otherwise
			else {
				//     Congratulate the recruit on guessing the secret words
				cout << "\nCongratulations, " << user << ", you got the word.";
			}
		}
		// Ask the recruit if they would like to run the simulation again
		cout << "\n\nWould you like to try again?";
		cin >> playAgain;
		//     Increment the number of simiulations ran counter
		++numOfSims;
		//     Move program execution back up to // Display the simulation # is staring to the recruit. 
	} while (playAgain == 'y' || playAgain == 'Y'); // If the recruit wants to run the simulation again
	// Otherwise 
	//     Display End of Simulations to the recruit
	cout << "Thanks for taking part.\n";
	//     Pause the Simulation with press any key to continue
	system("pause");
	return 0;
}