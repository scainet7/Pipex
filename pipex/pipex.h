#ifndef PIPEX_H
#define PIPEX_H

#define RED "\033[31m"
#define GREEN "\033[32m"
#define END "\033[0m\n"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "libft/libft.h"

typedef struct s_parametrs
{
	char *paths;
	char **cmd_paths;
	pid_t pid_first;
	pid_t pid_second;
	int pipe_fd[2];
} t_parametrs;

#endif //PIPEX_H
