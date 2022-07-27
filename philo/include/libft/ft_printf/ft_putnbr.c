/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:08:46 by rade-sar          #+#    #+#             */
/*   Updated: 2021/12/16 16:38:53 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		size += ft_putchar('-');
		n = -n;
	}
	if (n < 10)
		size += ft_putchar(n + '0');
	else
	{
		size += ft_putnbr(n / 10);
		size += ft_putnbr(n % 10);
	}
	return (size);
}

int	ft_put_unsigned_nbr(unsigned int n)
{
	int		size;

	size = 0;
	if (n < 10)
		size += ft_putchar(n + '0');
	else
	{
		size += ft_put_unsigned_nbr(n / 10);
		size += ft_put_unsigned_nbr(n % 10);
	}
	return (size);
}
