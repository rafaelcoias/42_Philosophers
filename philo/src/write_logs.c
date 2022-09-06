/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:02:58 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/06 01:05:19 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	write_logs(int time, int philo, char *log, t_data *data)
{
	pthread_mutex_lock(&(data->mutex));
	printf(YELLOW);
	if (!ft_strcmp(log, DIED))
		printf(RED);
	printf("%i %i %s\n", time, philo, log);
	printf(RESET);
	pthread_mutex_unlock(&(data->mutex));
}
