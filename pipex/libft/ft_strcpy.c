#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	if (dest == ((void *)0) || src == ((void *)0))
		return (0);
	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}