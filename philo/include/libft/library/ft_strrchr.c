/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:12:47 by rade-sar          #+#    #+#             */
/*   Updated: 2021/10/28 21:36:38 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*aux;
	unsigned char	lt;

	aux = (unsigned char *)s;
	lt = c;
	while (*s != '\0')
	{
		if (*s == lt)
		{
			aux = (unsigned char *)s;
			s++;
			while (*s != lt && *s != '\0')
				s++;
			if (*s == lt)
				continue ;
			if (*s == '\0')
				return ((char *)aux);
		}
		s++;
	}
	if (*s == '\0' && lt == '\0')
		return ((char *)s);
	return (NULL);
}
