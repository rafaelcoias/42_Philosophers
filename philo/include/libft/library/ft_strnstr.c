/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:38:24 by rade-sar          #+#    #+#             */
/*   Updated: 2021/10/25 21:45:15 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	size;
	char	*str;

	i = 0;
	str = (char *)haystack;
	size = ft_strlen(needle);
	if (size == 0 || haystack == needle)
		return (str);
	while (str[i] != '\0' && i < len)
	{
		c = 0;
		while (str[i + c] != '\0' && needle[c] != '\0'
			&& str[i + c] == needle[c] && i + c < len)
			c++;
		if (c == size)
			return (str + i);
		i++;
	}
	return (0);
}
