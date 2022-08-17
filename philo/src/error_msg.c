/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:51:53 by rade-sar          #+#    #+#             */
/*   Updated: 2022/08/17 21:01:50 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	error_msg(char *str)
{
	printf(RED);
	write(2, "\nError\n", 7);
	printf(RESET);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}
