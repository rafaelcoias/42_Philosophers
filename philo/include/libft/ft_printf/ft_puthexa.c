/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:19:07 by rade-sar          #+#    #+#             */
/*   Updated: 2021/12/16 16:40:24 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char *base)
{
	int		size;

	size = 0;
	if (n > 15)
	{
		size += ft_puthexa((n / 16), base);
		size += ft_putchar(base[n % 16]);
	}
	else
		size += ft_putchar(base[n]);
	return (size);
}
