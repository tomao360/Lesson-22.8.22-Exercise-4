#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable :4996)

void readFileAndEnterIntOrChar()
{
	FILE* f = fopen("C:\\week2 lesson 08.22 C\\File3.txt", "r");

	if (f != NULL)
	{
		int* ptrInt; 
		int* startInt;
		char* ptrChar;
		char* startChar;
		int number;
		char ch = 0;

		while (ch != EOF)
		{
			number = fgetc(f) - '0'; //convert a character to an integer
			ch = fgetc(f); 

			if (ch != EOF)
			{
				if (ch == 'c')
				{
					ptrChar = malloc(number * sizeof(char)); //memory allocation of characters
					startChar = ptrChar; //will stay in the beginning of ptrChar (important for free)

					printf("Please enter %d characters:\n", number);
					for (int i = 0; i < number; i++) //a loop for receiving characters from the user according to the number in the file
					{
						char character;
						scanf(" %c", &character); //needs space in the beginning because when you press ENTER its counted as a character
						*ptrChar = character;
						*ptrChar++;
					}

					free(startChar);
				}

				if (ch == 'i')
				{
					ptrInt = malloc(number * sizeof(int)); //memory allocation of integers
					startInt = ptrInt; //will stay in the beginning of ptrInt (important for free)

					printf("Please enter %d integer numbers:\n", number); 
					for (int i = 0; i < number; i++) //a loop for receiving integers from the user according to the number in the file
					{
						int num;
						scanf("%d", &num);
						*ptrInt = num;
						*ptrInt++;
					}

					free(startInt);
				}
			}
		}

		fclose(f);
	}
	else
	{
		printf("ERROR, the file is empty\n");
	}
}
	

int main()
{
	readFileAndEnterIntOrChar();

	return 0;
}