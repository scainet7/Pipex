#include "libft.h"

void	ft_free_split(char **tmp)
{
	int i;

	if (!tmp)
		return ;
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}
