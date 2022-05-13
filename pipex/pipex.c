#include "pipex.h"

int fd_parent()
{

}

int fd_child()
{

}

int main(int argc, char **argv, char **envp)
{
    int proc;

    if (argc != 5)
        exit(EXIT_FAILURE);
    if (proc == 0)
        fd_child();
    fd_parent();
    return 0;
}
