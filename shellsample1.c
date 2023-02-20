#include "shell.h"


int main(int count, char **input)
{
	char *prompt = "Shellsample/$: ";
	char *userinput;
	size_t usercounter = 0; // we could use size_t datatype if int does not work. 
	printf("%s", prompt);

	getline(&userinput, &usercounter, stdin);
	printf("%s\n", userinput);

	free(userinput);
	return 0;
}
