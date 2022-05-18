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

char *ft_find_path(char **envp)
{
	char	**arg;
	int 		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			arg = ft_split(envp[i] + 5, ':');
			if (!arg)
				ft_error(RED"ERROR"END);
			return (*arg);
		}
		i++;
	}
	return (NULL);
}

char *ft_cmd(t_parametrs *params)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	while (params->paths[i])
	{
		tmp = ft_strjoin(&params->paths[i], "/");
		line = ft_strjoin(tmp, *params->cmd_paths);
		free(tmp);
		if (access(line, F_OK) == 0)
			return (line);
		else
			free(line);
		i++;
	}
	return (NULL);
}

void ft_parent(char **argv, char **envp, t_parametrs *params)
{
	dup2(params->infile, 0);
	dup2(params->pipe_fd[1], 1);
	params->cmd_paths = ft_split(argv[2], ' ');
	params->paths = ft_find_path(envp);
	params->line = ft_cmd(params);
	close(params->infile);
	close(params->pipe_fd[1]);
	execve(*params->cmd_paths, &params->paths, &params->line);
}


void ft_descendant(char **argv, char **envp, t_parametrs *params)
{
	dup2(params->infile, 0);
	dup2(params->pipe_fd[1], 1);
	params->cmd_paths = ft_split(argv[2], ' ');
	params->paths = ft_find_path(envp);
	params->line = ft_cmd(params);
	close(params->infile);
	close(params->pipe_fd[1]);
	execve(*params->cmd_paths, &params->paths, &params->line);
}

int main(int argc, char **argv, char **envp)
{
	t_parametrs params;
	if (argc != 5)
	{
		if (argc < 5)
			ft_error(RED"ERROR_MANY_ARGUMENTS"END);
		else
			ft_error(RED"ERROR_MORE_ARGUMENTS"END);
	}
	if (envp == 0)
		ft_error(RED"ERROR_ENVP"END);
	ft_check_fd(argv, &params);
	if (pipe(params.pipe_fd) < 0)
		ft_error(RED"ERROR_PIPE"END);
	params.pid_first = fork();
	if (params.pid_first < 0)
		ft_error(RED"ERROR_FORK"END);
	if (params.pid_first == 0)
		ft_descendant(argv, envp, &params);
	ft_parent(argv, envp, &params);

	return 0;
}
