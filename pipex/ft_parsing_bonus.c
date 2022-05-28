#include "pipex_bonus.h"

static char	**ft_find_path(char **envp)
{
	int		i;
	char	**path;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		{
			path = ft_split(envp[i] + ft_strlen("PATH="), ':');
			if (!*path)
				ft_error(RED"ERROR_PATH_SPLIT"END);
			return (path);
		}
		i++;
	}
	if (!envp[i])
		ft_error(RED"ERROR_NO_PATH_IN_ENVP"END);
	return (NULL);
}

static char	*ft_check_cmd(char **path, char *tmp_cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], tmp_cmd);
		if (!tmp)
			ft_error(RED"ERROR_TMP_CMD_STRJOIN"END);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		else
			free(tmp);
	}
	return (NULL);
}

static char	**ft_find_cmd(char *cmd_string, char **envp)
{
	char	**path;
	char	**cmd;
	char	*tmp_cmd;
	char	*tmp;

	path = ft_find_path(envp);
	cmd = ft_split(cmd_string, ' ');
	if (!cmd)
		ft_error(RED"ERROR_CMD_SPLIT"END);
	tmp_cmd = ft_strjoin("/", *cmd);
	if (!tmp_cmd)
		ft_error(RED"ERROR_TMP_CMD_STRJOIN"END);
	tmp = *cmd;
	*cmd = ft_check_cmd(path, tmp_cmd);
	if (*cmd)
		return (cmd);
	free(tmp);
	free(tmp_cmd);
	ft_free_split(path);
	return (NULL);
}

static void	ft_check_file(t_parametrs *pip, int argc)
{
	if (ft_strnstr(pip->argv[1], "here_doc", ft_strlen("here_doc")))
	{
		pip->lim = pip->argv[2];
		pip->n = 1;
		pip->infile = 0;
		pip->outfile = open(pip->argv[argc-1], O_WRONLY | O_APPEND | O_CREAT,
							0777);
		if (pip->outfile < 0)
			ft_error(RED"ERROR_CAN_NOT_OPEN_OUTFILE"END);
		pip->num_cmd = argc - 1 - 3;
	}
	else
	{
		pip->lim = NULL;
		if(access(pip->argv[1], F_OK) < 0)
			ft_error(RED"ERROR_INFILE_DOES_NOT_EXIST"END);
		pip->infile = open(pip->argv[1], O_RDONLY);
		if (pip->infile < 0)
			ft_error(RED"ERROR_CAN_NOT_OPEN_INFILE"END);
		pip->outfile = open(pip->argv[argc-1], O_WRONLY | O_APPEND | O_CREAT,
							0777);
		if (pip->outfile < 0)
			ft_error(RED"ERROR_CAN_NOT_OPEN_OUTFILE"END);
		pip->num_cmd = argc - 1 - 2;
	}
}

t_parametrs	*ft_check_args(int argc, char **argv, char **envp)
{
	t_parametrs		*pip;
	int 			i;

	pip = (t_parametrs *) malloc(sizeof (t_parametrs));
	if (!pip)
		ft_error(RED"ERROR_MALLOC_STRUCT"END);
	pip->argv = argv;
	if (argc < 5 || (argc < 6 && ft_strnstr(pip->argv[1],
		"here_doc", ft_strlen("here_doc"))))
		ft_error(RED"ERROR_MANY_ARGUMENTS"END);
	pip->n = 0;
	ft_check_file(pip, argc);
	pip->cmd = (char ***) malloc(sizeof (char **)*(pip->num_cmd + pip->n + 1));
	if (!pip->cmd)
		ft_error(RED"ERROR_MALLOC_CMD"END);
	pip->cmd[pip->num_cmd + pip->n] = NULL;
	if (pip->n)
		pip->cmd[0] = NULL;
	if (envp == 0)
		ft_error(RED"ERROR_ENVP"END);
	i = -1;
	while (++i < pip->num_cmd)
		pip->cmd[i + pip->n] = ft_find_cmd(pip->argv[argc - 1 - pip->num_cmd + i], envp);
	return (pip);
}
