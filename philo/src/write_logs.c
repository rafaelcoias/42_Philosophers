/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:02:58 by rade-sar          #+#    #+#             */
/*   Updated: 2022/08/17 21:01:24 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	write_log(int time, int philo, char *log)
{
	printf(YELLOW);
	if (!ft_strcmp(log, DIED))
		printf(RED);
	printf("%i %i %s\n", time, philo, log);
	printf(RESET);
}
