#include "pipex_bonus.h"

void ft_close_fd(t_parametrs *params)
{
	int	i;

	i = -1;
	while (++i < (params->num_cmd + params->n - 1)*2)
		close(params->pipe_fd[i]);
	if (!params->n)
		close(params->infile);
	close(params->outfile);
}

void static ft_child(char **cmd, int fd_in, int fd_out, t_parametrs *params)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	ft_close_fd(params);
	execve(cmd[0], cmd, NULL);
	ft_error("ERROR_EXECVE");
	exit (127);
}

void static ft_child_stdin(int fd_in, int fd_out, t_parametrs *params)
{
	char	*line;
	int		r;

	while (1)
	{
		r = gnl(fd_in, &line);
		if ((r == 0 && !line) || r == -1)
			break ;
		if (ft_strnstr(params->lim, line, ft_strlen(params->lim)))
			break ;
		write(fd_out, line, ft_strlen(line));
		if (r != 0)
			write(fd_out, "\n", 1);
		free(line);
	}
	ft_close_fd(params);
	exit (0);
}

void static ft_child_proc(t_parametrs *params)
{
	int	i;

	i = -1;
	while (++i < params->num_cmd + params->n)
	{
		params->pid[i] = fork();
		if (params->pid[i] < 0)
			ft_error(RED"ERROR_FORK"END);
		if (params->pid[i] == 0)
		{
			if (i == 0 && params->lim)
				ft_child_stdin(params->infile, params->pipe_fd[i * 2 + 1], params);
			else if (i == 0)
				ft_child(params->cmd[i], params->infile, params->pipe_fd[i *
				2 + 1], params);
			else if (i == params->num_cmd - 1 + params->n)
				ft_child(params->cmd[i], params->pipe_fd[2 * (i - 1)], \
						 params->outfile, params);
			else
				ft_child(params->cmd[i], params->pipe_fd[2 * (i - 1)], \
						params->pipe_fd[i * 2 + 1], params);
		}
	}
}

void ft_parrent(t_parametrs *params)
{
	int	i;

	i = -1;
	while (++i < params->num_cmd - 1 + params->n)
	{
		if(pipe(params->pipe_fd + i * 2) < 0)
			ft_error(RED"ERROR_PIPE"END);
	}
	ft_child_proc(params);
	ft_close_fd(params);
	i = -1;
	while (++i < params->num_cmd + params->n)
		waitpid(params->pid[i], &params->status[i], 0);

}
