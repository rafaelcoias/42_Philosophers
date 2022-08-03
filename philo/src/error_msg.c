/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:51:53 by rade-sar          #+#    #+#             */
/*   Updated: 2022/08/03 16:56:13 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	error_msg(char *str)
{
	write(2, RED, 7);
	write(2, "\nError\n", 7);
	write(2, RESET, 4);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}
