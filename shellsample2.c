#include "shell.h"


int main(int *count, int **characters)
{
	char *prompt = "Shellsample/$: ";
	char *userinput;
	char *userinput_copy;
	
	size_t usercounter = 0; // we could use size_t datatype if int does not work. 
	ssize_t getline_failure;

	while(true)
	{
		printf("%s", prompt);

		getline_failure = getline(&userinput, &usercounter, stdin);

		if (getline_failure == -1)
		{
			printf("Exiting the shell in 3, 2, 1, Pooooooof\n");
			return -1;
		}

		userinput_copy = malloc(sizeof(char) * getline_failure);
		if (userinput_copy == NULL)
		{
			printf("Eish!, Error in Allocation");
			return -1;
		}

		strcpy(userinput_copy, userinput);
		
		//char delimiter = " ";
		int *stringtok_result = strtok(userinput, " ");
		while(stringtok_result != NULL)
		{
			stringtok_result = strtok(NULL, " ");
			stringtok_result++;
		}
		
		
		printf("%s\n", userinput);
		
	}
	free(userinput);
	return 0;
}
