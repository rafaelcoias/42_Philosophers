/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:16:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/08 05:50:45 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	end_simulation(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (++i <= data->n_philo)
	{
		philo = data->philo->next;
		pthread_mutex_destroy(&data->fork[data->philo->id - 1]);
		free(data->philo);
		data->philo = philo;
	}
	free(data->fork);
	pthread_mutex_destroy(&(data->mutex));
}
