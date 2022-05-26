/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:09:28 by snino             #+#    #+#             */
/*   Updated: 2022/05/15 18:09:33 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

static void	ft_descendant_1(t_parametrs *params, char **envp)
{
	dup2(params->infile, 0);
	dup2(params->pipe_fd[1], 1);
	close(params->infile);
	close(params->outfile);
	close(params->pipe_fd[0]);
	close(params->pipe_fd[1]);
	execve(params->cmd_first[0], params->cmd_first, envp);
	ft_error(RED"ERROR_EXECVE"END);
	exit(127);
}

static void	ft_descendant_2(t_parametrs *params, char **envp)
{
	dup2(params->outfile, 1);
	dup2(params->pipe_fd[0], 0);
	close(params->infile);
	close(params->outfile);
	close(params->pipe_fd[0]);
	close(params->pipe_fd[1]);
	execve(params->cmd_second[0], params->cmd_second, envp);
	ft_error(RED"ERROR_EXECVE"END);
	exit(127);
}

static void	ft_fork(t_parametrs *params, char **envp)
{
	int	pid[2];
	int	status[2];

	pid[0] = fork();
	if (pid[0] < 0)
		ft_error(RED"ERROR_FORK_1"END);
	if (pid[0] == 0)
		ft_descendant_1(params, envp);
	pid[1] = fork();
	if (pid[1] < 0)
		ft_error(RED"ERROR_FORK_2"END);
	if (pid[1] == 0)
		ft_descendant_2(params, envp);
	close(params->infile);
	close(params->outfile);
	close(params->pipe_fd[0]);
	close(params->pipe_fd[1]);
	waitpid(pid[0], &status[0], 0);
	waitpid(pid[1], &status[1], 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_parametrs	*params;

	params = (t_parametrs *) malloc(sizeof (t_parametrs));
	if (!params)
		ft_error(RED"ERROR_MALLOC_STRUCT"END);
	ft_check_args(argc, argv, envp, params);
	if (pipe(params->pipe_fd) < 0)
		ft_error(RED"ERROR_PIPE"END);
	ft_fork(params, envp);
	ft_free_split(params->cmd_first);
	ft_free_split(params->cmd_second);
	free(params);
	return (0);
}
