#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


int main(int count, char **texts)
{
    char *prompt = "$: ";
    ssize_t getline_result;
    size_t *size = 0, i = 0;
    char *userinput = NULL, *userinput_copy = NULL;
    char *tokenization = NULL; 
    int tokenization_counter = 0;
    pid_t pid;
    char *tokenization_delimiter = " \n";
    char *arguements[] = {"/bin/", "-l", NULL}; 

    
    while (1)
    {
        pid = fork();

        if (pid == -1)
        {
            perror("Fork!");
            return pid; // return -1; anyone works
        }

        if (pid == 0)
        {
        printf("%s", prompt);

        getline_result = getline(&userinput, &size, stdin);
        if(getline_result == -1)
        {
            perror("Error, Exiting Now!!");
            return -1;
        }

        
        userinput_copy = malloc(sizeof(char) * getline_result);
        if (userinput_copy == NULL)
        {
            perror("User INput Copy is NULL");
            return -1;
        }
        strcpy(userinput_copy, userinput);


        tokenization = strtok(userinput_copy, tokenization_delimiter);
        if (tokenization == NULL)
        {
            perror("Unable to tokenize Input");
            return -1;
        }

        while (tokenization != NULL)
        {
            tokenization_counter++;
            tokenization = strtok(NULL, tokenization_delimiter);
        }
        tokenization_counter++;


        texts = malloc(sizeof(char *) * tokenization_counter);
        tokenization = strtok(userinput, tokenization_delimiter);

        while (tokenization != NULL)
        {
            texts[i] = malloc(sizeof(char) * strlen(tokenization));
            strcpy(texts[i], tokenization);

            printf(">>>>> %s \n", texts[i]);

            tokenization = strtok(NULL, tokenization_delimiter);
        }
        texts[i] = NULL;

        int val = execve(arguements[0], texts, NULL);
        if (val == -1)
        {
            perror("Error");
            return -1;
        }

        if (arguements[0] == NULL)
        {
            perror("No such file in Directory");
            break;
        }


        //printf("%s\n", userinput);

        free(userinput);
        free(userinput_copy);
        free(texts);
        }
        else
        {
            wait(NULL);
            return pid;
        }
    }
    
    return 0;
}
