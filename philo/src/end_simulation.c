/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:16:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/12 14:41:39 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	end_simulation(t_data *data)
{
	t_philo	*philo;
	int		i;

	if (data->n_philo == 1)
	{
		free(data->philo);
		return ;
	}
	i = 0;
	while (++i <= data->n_philo)
	{
		philo = data->philo->next;
		pthread_mutex_destroy(&(data->fork[i - 1]));
		free(data->philo);
		data->philo = philo;
	}
	free(data->fork);
	destroy_mutex(data->logs);
	destroy_mutex(data->check_end);
}

static void	check_death(t_data *data, t_philo *philo)
{
	if (philo->last_meal
		&& get_time() - data->t0 - philo->last_meal > data->t_die)
	{
		data->end = 1;
		printf("%s%lli ms%s | %sPhilo %i %s\n", BLUE,
			get_time() - data->t0, RESET, RED, philo->id, DIED);
		break ;
	}
}

void	*check_end(void *d)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)d;
	philo = data->philo;
	while (1)
	{
		lock_mutex(data->check_end);
		check_death(data, philo);
		if (data->n_eat && data->all_ate == data->n_philo)
		{
			data->end = 1;
			break ;
		}
		unlock_mutex(data->check_end);
		philo = philo->next;
	}
	unlock_mutex(data->check_end);
	return (NULL);
}
