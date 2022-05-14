#include "pipex.h"

void fd_error(char *s)
{
	printf("%s",s);
	exit(EXIT_FAILURE);
}
/*
char fd_error(char *s)
{

}

int fd_parent()
{

}

int fd_child()
{

}
*/
int main(int argc, char **argv, char **envp)
{
    if (argc != 5)
    {
    	if (argc < 5)
    		fd_error("\033[31m ERROR_MORE_ARGUMENTS \0m\n");
    	else
    		fd_error("\033[31m ERROR_MORE_ARGUMENTS \0m\n");
    }
    if (envp != 0)
    	exit(EXIT_FAILURE);
    /*int proc;
    pid_t file[2];
    if (proc == 0)
        fd_child(argc, *argv, envp, file[2]);
    fd_parent();*/
    return 0;
}
