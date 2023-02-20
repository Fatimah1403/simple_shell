#include "shell.h"


int main()
{
	char *prompt = "Shellsample/$: ";
	char *userinput;
	size_t usercounter = 0; // we could use size_t datatype if int does not work. 
	ssize_t getline_failure;

	while(1)
	{
		printf("%s", prompt);

		getline_failure = getline(&userinput, &usercounter, stdin);

		if (getline_failure == -1)
		{
			printf("Exiting the shell in 3, 2, 1, Pooooooof\n");
			return -1;
		}

		printf("%s\n", userinput);

//		free(userinput);   using this free here woi;d make the code break on second trial. so the buffer if freed when the code breaks or the program ends
	}
	free(userinput);
	return 0;
}
