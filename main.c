#include <stdio.h> //for printf() and scanf().
#include <string.h> //for strlen().
#include <stdlib.h> //for exit() and srand().
#include <time.h> //for time().
#include "menu.h" //for welcome() and isEnd().
#include "main.h" //for play().
#include "functions.h" //for setWord(), setSecretWord(), getChar(), isIn(), and isDiscovered().

int main (int argc, char *argv[])
{
	newGame();
	return 0;
}

void newGame ()
{
	int tryLeft = welcome();
	play(&tryLeft);
}


/*
 * This function is the main part of the game:
 * The user enter several char, and the function
 * returns the result of the user's choice.
 */
void play(int *chances) //I'M ASSUMMING THAT EVERY WORD HAS NO MORE THAN 30 LETTERS!
{
	srand(time(NULL)); //set a new seed for rand() -in setWord()- after each game.
	char word[30] = {0}; //create an empty word.
	setWord(word); //set the word to a word in the file 'words.txt'.
	char secret[30]; //creating my secret word.
	setSecretWord(word, secret); //setting the secret word to a series of '*'.

	//now both words are 30 characters long!
	//need to test the char ' ' to remove all "spaces" from the word!!
	isIn (word, ' ', secret, chances);

	printf("\nPress enter to start a new Game!"); //those 2 lines are just here to debug the function getChar().
	char bug = getChar(); //It doesn't work when it's the first time that we call it...
	printf("\a"); //BIP!
	
	while (*chances > 0)
	{
		printf("\nYou have %d chances.", *chances);
		printf("\nThe secret word is: %s", secret);
		printf("\nEnter a character that may be in the word: ");
		
		char guess = getChar(); //read a char form the user. Function located in the file 'getChar.h'
		
		isIn(word, guess, secret, chances); //is it a good guess: yes-update secret
		
		if (isDiscovered(secret)) //if the secret word is discovered:
		{
			printf("\nThe secret word was: %s", secret);
			printf("\nYou discovered the secret word! Congratulation!\n");
			
			if(!isEnd()) newGame();
			else exit(0);
		}
	}
	//if I reach this line, the user used all his chances!
	printf("\nNO! You killed someone! :(\n");
	printf("The secret word was: %s", word);
	if(!isEnd()) newGame();
	else exit(0);
}
