#include "pipex.h"

void ft_error(char *s)
{
	ft_putstr_fd(s,2);
	exit(EXIT_FAILURE);
}

void ft_check_fd(char **argv, t_parametrs *params)
{
	if (access(argv[1], F_OK))
		ft_error(RED"ERROR_INFILE_DOES_NOT_EXIST"END);
	else if (access(argv[1], R_OK) != 0)
		ft_error(RED"ERROR_INFILE_READ"END);
	params->infile = open(argv[1], O_RDONLY);
	if (access(argv[4], F_OK))
		params->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (access(argv[4], W_OK))
		ft_error(RED"ERROR_OUTFILE_READ"END);
	else
	{
		unlink(argv[4]);
		params->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
}

