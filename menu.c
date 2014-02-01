#include <stdio.h> //for printf() and scanf()

int welcome()
{
	int tryLeft = 0;
	
    printf("\n==========WELCOME TO THE HANG-MAN GAME!==========");
    printf("\n\n 1: Easy (15 chances)");
	printf("\n 2: Normal (10 chances)");
	printf("\n 3: Hard (5 chances)\n");

	int choice = 0;
	scanf ("%d", &choice);

	switch(choice)
	{
	case 1:
		tryLeft = 15;
		printf("\nYou have to guess a word (IN CAPITAL LETTERS) in 15 tries");
		break;
	case 2:
		tryLeft = 10;
		printf("\nYou have to guess a word (IN CAPITAL LETTERS) in 10 tries");
		break;
	case 3:
		tryLeft = 5;
		printf("\nYou have to guess a word (IN CAPITAL LETTERS) in 5 tries");
		break;
	default:
		printf("Make sure to only enter 1 or 2 or 3!");
		welcome();
		break;
	}
	return tryLeft;
}

int isEnd()
{
	printf("\nDo you want to play again?");
	printf("\n 1: Yes");
	printf("\n 0: No\n");

	int choice = 0;
	scanf("%d", &choice);

	switch(choice)
	{
	case 1:
		return 0;
	case 0:
		return 1;
	default:
		printf("Make sure to only enter 1 or 0!");
		isEnd();
		break;
	}
}
