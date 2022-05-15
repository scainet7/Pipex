/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:46:04 by snino             #+#    #+#             */
/*   Updated: 2021/10/14 20:43:35 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	a = (char *) dst;
	b = (char *) src;
	if (a > b)
	{
		while (n--)
		{
			a[n] = b[n];
		}
	}
	else
		ft_memcpy(a, b, n);
	return (dst);
}
