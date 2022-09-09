/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:16:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/09 02:19:44 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	end_simulation(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (data->n_philo != 1 && ++i <= data->n_philo)
	{
		philo = data->philo->next;
		pthread_mutex_destroy(&(data->fork[i - 1]));
		free(data->philo);
		data->philo = philo;
	}
	if (data->n_philo == 1)
		free(data->philo);
	free(data->fork);
	if (data->n_philo != 1)
		if (pthread_mutex_destroy(&(data->mutex)))
			error_msg(DESTROY_MUTEX);
}

void	*check_end(void *d)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)d;
	philo = data->philo;
	while (!data->end)
	{
		if (philo->last_meal &&
				get_time() - data->t0 - philo->last_meal > data->t_die)
		{
			philo->death = 1;
			data->end = 1;
			printf("%s%lli ms%s | %sPhilo %i %s\n", BLUE,
			 get_time() - data->t0, RESET, RED, philo->id, DIED);
		}
		if (data->n_eat && data->all_ate == data->n_philo)
			data->end = 1;
		if (data->philo->death || data->end)
			break ;
		philo = philo->next;
	}
	return (NULL);
}
