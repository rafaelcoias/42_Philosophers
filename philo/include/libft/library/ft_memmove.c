/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:33:45 by rade-sar          #+#    #+#             */
/*   Updated: 2021/10/28 21:44:18 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*aux;
	const char	*str;

	if (dst == NULL)
		return (NULL);
	aux = dst;
	str = src;
	if (dst <= src)
		while (len--)
			*aux++ = *str++;
	else
	{
		aux = aux + len;
		str = str + len;
		while (len--)
			*--aux = *--str;
	}
	return (dst);
}

