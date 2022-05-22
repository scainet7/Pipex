#include "pipex.h"

static char **ft_find_path(char **envp)
{
	int		i;
	char	**path;

	path = NULL;
	i = -1;
	while(envp[++i])
	{
		if(ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		{
			path = ft_split(envp[i] + ft_strlen("PATH="), ':');
			break;
		}
	}
	if (!envp[i])
		ft_error(RED"ERROR_NO_PATH_IN_ENVP"END);
	if (!*path)
		ft_error(RED"ERROR_PATH_SPLIT"END);
	return (path);
}

static char *ft_check_cmd(char **path, char *tmp_cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], tmp_cmd);
		if(!tmp)
			ft_error(RED"ERROR_TMP_CMD_STRJOIN"END);
		if(access(tmp, F_OK) == 0)
			return (tmp);
		else
			free(tmp);
	}
	return (NULL);
}

static char **ft_find_cmd(char *cmd_string, char **envp)
{
	char **path;
	char **cmd;
	char *tmp_cmd;
	char *tmp;

	path = ft_find_path(envp);
	cmd = ft_split(cmd_string, ' ');
	if(!cmd)
		ft_error(RED"ERROR_CMD_SPLIT"END);
	tmp_cmd = ft_strjoin("/", *cmd);
	if(!tmp_cmd)
		ft_error(RED"ERROR_TMP_CMD_STRJOIN"END);
	tmp = *cmd;
	*cmd = ft_check_cmd(path, tmp_cmd);
	if(!(*cmd))
		ft_error(RED"ERROR_NO_ACCESS_CMD"END);
	free(tmp);
	free(tmp_cmd);
	ft_free_split(path);
	return (cmd);
}

static void ft_parsing(t_parametrs *params, char **envp)
{
	if (access(params->argv[1], F_OK))
		ft_error(RED"ERROR_INFILE_DOES_NOT_EXIST"END);
	else if (access(params->argv[1], R_OK) != 0)
		ft_error(RED"ERROR_INFILE_READ"END);
	params->infile = open(params->argv[1], O_RDONLY);
	params->outfile = open(params->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	params->cmd_first = ft_find_cmd(params->argv[2], envp);
	params->cmd_second = ft_find_cmd(params->argv[3], envp);
}

void ft_check_args(int argc, char **argv, char **envp, t_parametrs *params)
{
	if (argc != 5)
	{
		if (argc < 5)
			ft_error(RED"ERROR_MANY_ARGUMENTS"END);
		else
			ft_error(RED"ERROR_MORE_ARGUMENTS"END);
	}
	if (envp == 0)
		ft_error(RED"ERROR_ENVP"END);
	params->argv = argv;
	if (access(argv[1], F_OK))
		ft_error(RED"ERROR_INFILE_DOES_NOT_EXIST"END);
	else if (access(argv[1], R_OK) != 0)
		ft_error(RED"ERROR_INFILE_READ"END);
	params->infile = open(argv[1], O_RDONLY);
	params->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_parsing(params, envp);
}

