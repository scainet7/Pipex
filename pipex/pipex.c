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

void ft_error(char *s)
{
	ft_putstr_fd(s,2);
	exit(EXIT_FAILURE);
}

void check_fd(char **argv, t_parametrs params)
{
    if (access(argv[1], F_OK))
        ft_error(RED"ERROR_INFILE_DOES_NOT_EXIST"END);
    else if (access(argv[1], R_OK) != 0)
        ft_error(RED"ERROR_INFILE_READ"END);
    params.infile = open(argv[1], O_RDONLY);
    if (access(argv[4], F_OK))
        params.outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
    else if (access(argv[4], W_OK)
        ft_error(RED"ERROR_OUTFILE_READ"END);
    params.outfile = open(argv[4], O_RDWR | O_TRUNC);
}

void ft_first_cmd(char *argv, char **envp)
{

}
/*void fd_parent(int argc, char **argv, char **envp, t_parametrs params)
{

}
*/
void fd_descendant(char **argv, char **envp, t_parametrs params)
{
    dup2(params.infile, 0);
    dup2(params.pipe_fd[1], 1);
    params.cmd_paths = ft_split(argv[2], ' ');
    params.paths = find_path(envp);

	else if (dup2(params.pipe_fd[0], 0) < 0 || dup2(params.pid_first, 1) < 0
	   || close(params.pid_first) < 0 || close(params.pipe_fd[0]) < 0
	   || close(params.pipe_fd[1]) < 0)
		ft_error(RED"ERROR_DUP2"END);
	printf(GREEN"%s"END, envp[1]);
	ft_first_cmd(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
	t_parametrs params;
    if (argc != 5)
    {
    	if (argc < 5)
    		ft_error(RED" ERROR_MANY_ARGUMENTS"END);
    	else
    		ft_error(RED"ERROR_MORE_ARGUMENTS"END);
    }
    if (envp == 0)
		ft_error(RED"ERROR_ENVP"END);
    check_fd(argv, params);
    if (pipe(params.pipe_fd) < 0)
        ft_error(RED"ERROR_PIPE"END);
	params.pid_first = fork();
	if (params.pid_first < 0)
		ft_error(RED"ERROR_FORK"END);
	if (params.pid_first == 0)
		fd_descendant(argv, envp, params);
	//fd_parent(argc, argv, envp, params);

    return 0;
}
