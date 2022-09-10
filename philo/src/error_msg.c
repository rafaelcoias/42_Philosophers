/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:51:53 by rade-sar          #+#    #+#             */
/*   Updated: 2022/08/27 23:00:03 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	error_msg(char *str)
{
	write(2, RED, 7);
	write(2, "Error\n", 7);
	write(2, RESET, 4);
	write(2, str, ft_strlen(str));
	exit(1);
}