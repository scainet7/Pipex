#ifndef PIPEX_BONUS_H
#define PIPEX_BONUS_H

# define RED "\033[31m"
# define END "\033[0m\n"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef struct s_parametrs
{
	char 	*lim;
	char	**argv;
	char 	***cmd;
	int		*pipe_fd;
	int 	*pid;
	int 	*status;
	int		n;
	int 	num_cmd;
	int		infile;
	int		outfile;
}	t_parametrs;

void	ft_error(char *s);
void ft_parrent(t_parametrs *params);
t_parametrs	*ft_check_args(int argc, char **argv, char **envp);
#endif //PIPEX_BONUS_H
