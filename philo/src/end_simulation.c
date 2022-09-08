/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:16:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/08 01:30:46 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	end_simulation(t_data *data)
{
	t_philo	*philo;
	int		i;

	pthread_mutex_lock(&data->mutex);
	i = 0;
	while (++i <= data->n_philo)
	{
		philo = data->philo->next;
		free(data->philo);
		data->philo = philo;
	}
	pthread_mutex_unlock(&data->mutex);
	pthread_mutex_destroy(&(data->mutex));
}
