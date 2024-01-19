#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void rules_explanation();
int number_initalization(int, int);
int user_input(int, int);
void number_check(int, int, int, int);


int main() {

int hidden_number;
int guess;
int max_num = 15;
int min_num = 1;
int guess_counter = 3;
int adjust;

rules_explanation();

cout << "\nDo you want to customize the game? This includes adjusting the number of guesses, and maximum and minimum length of the number.\n Press 1 if so, 0 if not.\n\n";
cin >> adjust;

while (adjust == 1) {
	cout << "Enter the maximum length\n";
	cin >> max_num;

	cout << "Enter the minimum length\n";
	cin >> min_num;

	cout << "Enter the maximum guesses\n";
	cin >> guess_counter;
	
	while (max_num <= min_num) {
		cout << "Invalid. Maximum number must be lower than minimum number\n";
		cout << "Enter the maximum length\n";
		cin >> max_num;

		cout << "Enter the minimum length\n";
		cin >> min_num;
	}
	adjust = 0;
}



hidden_number = number_initalization(max_num, min_num);
number_check(hidden_number, max_num, min_num, guess_counter);


}



void rules_explanation() {

	cout << "\n\tWelcomes to the Number Guessing Game!\n\tHere, we'll provide a hidden random number from 1 to 15 and you'll have to guess within 3 tries.\n";
	cout << "\tFurthermore, I'll tell you whether the number you scored was higher or lower than the hidden number each time you take a guess!\n";
	cout << "\tRemember to have fun!\n\n";

}


int number_initalization(int max_num, int min_num) {

	srand(static_cast<unsigned int>(time(nullptr)));
	int number = rand() % max_num + 1 + min_num;
	return number;

}

int user_input(int max_num,int min_num) {
	
	int guess;
	cout << "Now then, enter your guess: ";
	cin >> guess;
	cout << endl;
	
	while (!(guess >= min_num && guess <= max_num)) {
		cout << "Guess was above or below restricted numbers. Now then, enter your guess: ";
		cin >> guess;
		cout << endl;
	} 
		
	return guess;
}


void number_check(int hidden_number, int max_num, int min_num, int max_guess_counter) {

	int guess_counter = 1;
	int guess;

	
	while (guess_counter <= max_guess_counter) {
		
		guess = user_input(max_num, min_num);
		
		if (guess == hidden_number) {
			cout << "Congrats! You guessed the number correctly. It took you " << guess_counter << " attempts to do it.\n\n";
			break;
		}
		
		if (guess_counter != hidden_number) {
			cout << "You didn't guess the number. You have " << max_guess_counter - guess_counter << " attempts left.\n";
			if (guess < hidden_number) {
				cout << "Your guess was below the hidden number.\n\n";
			}	
			if (guess > hidden_number)
				cout << "Your guess was above the hidden number\n\n";
		}
	
		guess_counter++;
		if (guess_counter == max_guess_counter + 1)
			cout << "The number was " << hidden_number << "\n\n";
		
}

}

