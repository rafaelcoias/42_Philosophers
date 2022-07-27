/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:01:01 by rade-sar          #+#    #+#             */
/*   Updated: 2021/10/27 16:27:38 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idest;
	size_t	isrc;
	size_t	result;

	idest = ft_strlen(dst);
	isrc = ft_strlen(src);
	if (dstsize <= idest)
		result = isrc + dstsize;
	else
		result = isrc + idest;
	while (*src != '\0' && (idest + 1) < dstsize)
	{
		dst[idest] = *src;
		idest++;
		src++;
	}
	dst[idest] = '\0';
	return (result);
}
