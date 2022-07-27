/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:03:56 by rade-sar          #+#    #+#             */
/*   Updated: 2021/12/16 16:08:32 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(unsigned long n, char *base, int start)
{
	unsigned long	i;
	int				size;

	i = n;
	size = 0;
	if (i == 0)
		return (ft_putstr("0x0"));
	if (start)
		size += ft_putstr("0x");
	if (i > 15)
	{
		size += ft_putvoid(i / 16, base, 0);
		size += ft_putchar(base[i % 16]);
	}
	else
		size += ft_putchar(base[i]);
	return (size);
}
