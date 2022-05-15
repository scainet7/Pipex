/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:03:13 by snino             #+#    #+#             */
/*   Updated: 2021/11/04 13:21:03 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	if (!haystack || !needle)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		n = 0;
		if (haystack[i] == needle[n])
		{
			while (i + n < len && haystack[i + n] == needle[n])
			{
				n++;
				if (needle[n] == '\0')
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
