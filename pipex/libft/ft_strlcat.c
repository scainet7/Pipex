/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:19:10 by snino             #+#    #+#             */
/*   Updated: 2021/11/01 18:57:22 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	res_d;
	size_t	res_s;

	res_d = ft_strlen(dst);
	res_s = ft_strlen(src);
	if (size <= res_d)
		return (size + res_s);
	i = 0;
	while (src[i] != '\0' && (res_d + i) < (size - 1))
	{
		dst[res_d + i] = src[i];
		i++;
	}
	dst[res_d + i] = '\0';
	return (res_d + res_s);
}
