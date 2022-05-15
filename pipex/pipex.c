#include "pipex.h"

void fd_error(char *s)
{
	ft_putstr_fd(s,2);
	exit(EXIT_FAILURE);
}

/*void fd_parent(int argc, char **argv, char **envp, int *pipe_fd)
{

}

void fd_descendant(int argc, char **argv, char **envp, int *pipe_fd)
{

}
*/
int main(int argc, char **argv, char **envp)
{
	//t_parametrs params;
    if (argc != 5)
    {
    	if (argc < 5)
    		fd_error(RED" ERROR_MANY_ARGUMENTS"END);
    	else
    		fd_error(RED"ERROR_MORE_ARGUMENTS"END);
    }
    if (envp == 0)
		fd_error(RED"ERROR_ENVP"END);
	int pid;
	pid = fork();
	if (pid < 0)
		fd_error(RED"ERROR_FORK"END);
	if (pid == 0)
	{
		printf("%d\n", argc);
		printf("%s\n", argv[0]);
	}
		//fd_descendant(argc, argv, envp, params.pipe_fd);
	//fd_parent(argc, argv, envp, params.pipe_fd);

    return 0;
}
