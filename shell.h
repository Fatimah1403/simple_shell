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
 */


typedef struct infodetails
{
	int readfd;

} info_t;







#endif
