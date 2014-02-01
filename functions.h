#ifndef DEF_FUNCTIONS
#define DEF_FUNCTIONS
//headers of FUNCTIONS.C
void setWord (char word[]);
void setSecretWord(char word[], char secret[]);
char getChar();
int isIn(char word[], char guess, char secret[], int *tryLeft);
int isDiscovered(char secret[]);
#endif
