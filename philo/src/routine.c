/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:52:22 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/08 01:38:05 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	eat(t_data *data, t_philo *philo)
{
	write_logs(philo->id, FORK_TAKEN, data);
	write_logs(philo->id, FORK_TAKEN, data);
	write_logs(philo->id, EATING, data);
	philo->ate++;
	if (data->n_eat && data->n_eat == philo->ate)
		if (++data->all_ate >= data->n_philo)
			data->end = 1;
}

void	*routine(void *p)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)p;
	data = philo->data;
	usleep(1000);
	while (!philo->death && !data->end)
	{
		eat(data, philo);
		usleep(1000);
		write_logs(philo->id, SLEEPING, data);	
		usleep(1000);
		write_logs(philo->id, THINKING, data);
	}
	return (NULL);
}
