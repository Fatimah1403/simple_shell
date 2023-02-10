#ifndef _SHELL_H
#define _SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limit.h>
#include <fcntl.h>
#include <errno.h>

/**
 * struct infodetails - contains the infomations passed to the funtions
 * containing prototype and pointers.
 *
 * @readfd: the fd to read line input
 * @arg: a string generated from getline containing arguements
 * @argv: an array of strings generated from arg
 * @argc: the argument count
 * @err_num: the error code for exit()s
 * @alias: the alias node
 */


typedef struct infodetails
{
	int readfd;
	char *arg;
	char **argv;
	int argc;
	int err_num;
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
int print_alias(list_t *node)


























#endif
