/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:14:43 by rade-sar          #+#    #+#             */
/*   Updated: 2021/10/28 21:38:17 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	char			lt;

	lt = c;
	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = lt;
		i++;
	}
	return (ptr);
}
