/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:52:22 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/06 02:41:55 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	eat(t_data *data, t_philo *philo)
{
	write_logs(data->time, philo->id, FORK_TAKEN, data);
	write_logs(data->time, philo->id, FORK_TAKEN, data);
	write_logs(data->time, philo->id, EATING, data);	
}

void	*routine(void *p)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)p;
	data = philo->data;
	usleep(1000);
	while (!philo->death)
	{
		eat(data, philo);
		usleep(1000);
		write_logs(data->time, philo->id, SLEEPING, data);	
		usleep(1000);
		write_logs(data->time, philo->id, THINKING, data);
	}
	return (NULL);
}
