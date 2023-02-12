#ifndef _SHELL_H
#define _SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;

} list_t;

/**
 * struct infodetails - contains the infomations passed to the funtions
 * containing prototype and pointers.
 *
 * @readfd: the fd to read line input
 * @arg: a string generated from getline containing arguements
 * @argv: an array of strings generated from arg
 * @argc: the argument count
 * @err_num: the error code for exit()s
 * @status: the return status of the last exec'd command
 * @history: the history node
 * @alias: the alias node
 */


typedef struct infodetails
{
	int readfd;
	char *arg;
	char **argv;
	int argc;
	int err_num;
	int status;
	list_t *history;
	list_t *alias;

} info_t;




/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* _exits.c */
char *_strchr(char *, char);

/* prototypes for 0-atoi.c */
int interactive(info_t *);
int _isalphabet(int);
int _atoi(char *);

/* prototypes for builtin.c */

int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* prototypes for builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);
int set_alias(info_t *info, char *str);
int unset_alias(info_t *info, char *str);

/*  error.c*/
void _eputs(char *);
int _eputchar(char);

/*  string.c*/
int _strcmp(char *, char *);


/*  string1.c*/
void _puts(char *);
int _putchar(char);

/*  error1.c */
int _erratoi(char *);
void print_error(info_t *, char *);

/* _environ.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* _lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* _lists1.c */
size_t print_list(const list_t *);
ssize_t get_node_index(list_t *, list_t *);
list_t *node_starts_with(list_t *, char *, char);






#endif
