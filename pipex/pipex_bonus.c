#include "pipex_bonus.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

static void	ft_pip_init(t_parametrs *params)
{
	params->pipe_fd = (int *) malloc(sizeof(int)*(params->num_cmd - 1 +params->n)*2);
	if (!params->pipe_fd)
		ft_error(RED"ERROR_MALLOC_PIPE_FD"END);
	params->pid = (int *) malloc(sizeof(int)*(params->num_cmd + params->n));
	if (!params->pid)
		ft_error(RED"ERROR_MALLOC_PID"END);
	params->status = (int *) malloc(sizeof(int)*(params->num_cmd + params->n));
	if (!params->status)
		ft_error(RED"ERROR_MALLOC_STATUS"END);
}

int	main(int argc, char **argv, char **envp)
{
	t_parametrs	*params;
	int 	i;

	params = ft_check_args(argc, argv, envp);
	ft_pip_init(params);
	ft_parrent(params);
	i = -1;
	while (++i < params->num_cmd + params->n)
		ft_free_split(params->cmd[i]);
	free(params->cmd);
	free(params->pipe_fd);
	free(params->pid);
	free(params->status);
	free(params);
	return (0);
}
