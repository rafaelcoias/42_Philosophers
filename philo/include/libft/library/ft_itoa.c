/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 03:51:04 by rade-sar          #+#    #+#             */
/*   Updated: 2021/10/25 18:55:17 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_malloc(int n, int count)
{
	if (n <= 0)
		return (count + 1);
	else
		return (count);
}

static char	*ft_strrev(char *str, int n)
{
	int		i;
	int		j;
	int		size;
	char	aux;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	j = size - 1;
	if (n < 0)
	{
		i++;
		size++;
	}
	while (i < size / 2)
	{
		aux = str[i];
		str[i] = str[j];
		str[j--] = aux;
		i++;
	}
	return (str);
}

static char	*ft_strnbr(char *str, int n)
{
	int		i;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
	}
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		aux;

	count = 0;
	aux = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (aux != 0)
	{
		aux = aux / 10;
		count++;
	}
	str = malloc(sizeof(char) * (ft_malloc(n, count) + 1));
	if (!str)
		return (0);
	str = ft_strnbr(str, n);
	str = ft_strrev(str, n);
	return (str);
}
