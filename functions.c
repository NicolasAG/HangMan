#include<string.h> //for strlen().
#include<stdlib.h> //for rand() and srand().
#include<stdio.h> //for getchar(), FILE, fopen(), printf(), fseek(), fgets(), fclose().
#include<ctype.h> //for toupper().
#define NUMBER_OF_LINES 41.0
#define SIZE_OF_LINE 30.0
#define SIZE_OF_FILE (NUMBER_OF_LINES * SIZE_OF_LINE)

/*
 * This function set the word to be discovered to
 * a random word chosen from the file "words.txt".
 */
void setWord(char word[])
{	
	int random = rand(); //create a random value.
	random = ((SIZE_OF_FILE*random)/RAND_MAX); //set random to a value between 0 and size of the file.
	random -= (random%30); //set random to 0%30: the cursor now starts at the begining of a line.

	FILE *list = fopen ("words.txt", "r"); //open the file.
	if (list == NULL)
	{
		printf("\nThe file 'words.txt' does not  exist!\n");
	}
	else //if it' open:
	{
		fseek(list, random, SEEK_SET); //put cursor random char after the begining.
		fgets(word, 30, list); //set word to a word in 'list.
		fclose(list); //close file.
	}
}

/*
 * This function sets the secret word to a sequence
 * of '*' according to the lenghth of the original
 * word.
 */
void setSecretWord(char word[], char secret[])
{
	int k=0;
	for (k=0; k<strlen(word); k++) //for the #of letters in "word":
	{
		secret[k] = '*'; //add the char '*' to the secret word.
	}
	secret[strlen(word)] = '\0'; //the last char of the secret word is set to be '\0'.
}


/*
 * This functions get the char of that the user enter.
 */
char getChar()
{
        char myChar = getchar(); //reading a character fromm the user.
        myChar = toupper(myChar); //putting the char in CAPITAL LETTER.

        /*Cleaning buffer: remove the other entries of the user
        (like ENTER or SPACE or another char).
        This avoid bugs when asking for multiple characters! */
        while (getchar() != '\n') ; //cleaning buffer.

        return myChar;
}


/*
 * This function returns a boolean:
 * If the user enter a char that IS in the original word.
 * If it is: update the word and return true,
 * if it is not: decrement #of tries and return false.
 */
int isIn(char word[], char guess, char secret[], int *tryLeft)
{
	int count=0;
	int i=0;
	for(i=0; i<strlen(word); i++) //going through the word.
	{
		if (word[i] == guess) //if the user had a good guess:
		{
			secret[i] = guess; //update the word.
			count++; //add one for each matching char!
		}
	}
	if (count>0) return 1; //if the #of matching char is > 0, return true!
	else //if the #of matching char is still 0:
	{
		*tryLeft -= 1; //lost a chance.
		return 0; //return false.
	}
}


/* This function returns a boolean:
 * If the secret word still contains misterious char ('*')
 * then return false, else return true.
 */
int isDiscovered(char secret[])
{
	int i=0;
	for (i=0; i<strlen(secret); i++)
	{
		//if there is a mystery char in the secret word, the user didn't win yet!
		if (secret[i] == '*') return 0; //return false.
	}
	//if I reach this line, the secret word was discovered.
	return 1; //return true.
}
