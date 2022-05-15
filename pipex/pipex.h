/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:09:42 by snino             #+#    #+#             */
/*   Updated: 2022/05/15 18:09:47 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#define RED "\033[31m"
#define GREEN "\033[32m"
#define END "\033[0m\n"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libft/libft.h"

typedef struct s_parametrs
{
	char *paths;
	char **cmd_paths;
	pid_t pid_first;
	pid_t pid_second;
	int pipe_fd[2];
	int infile;
	int outfile;
} t_parametrs;

void fd_descendant(char **argv, char **envp, t_parametrs params);
void ft_error(char *s);
void ft_first_cmd(char *argv, char **envp);
#endif //PIPEX_H
