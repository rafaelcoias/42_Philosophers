/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:03:44 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/12 11:05:40 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i != data->n_philo)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL))
			error_msg(MUTEX_ERROR);
		data->philo = data->philo->next;
		i++;
	}
}

void	create_mutexes(t_data *data)
{
	data->fork = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->fork)
		error_msg(MALLOC_ERROR);
	create_forks(data);
	if (pthread_mutex_init(&(data->logs), NULL))
		error_msg(MUTEX_ERROR);
	if (pthread_mutex_init(&(data->check_end), NULL))
		error_msg(MUTEX_ERROR);
}

void	destroy_mutex(pthread_mutex_t mutex)
{
	if (pthread_mutex_destroy(&mutex))
		error_msg(DESTROY_MUTEX);
}

void	lock_mutex(pthread_mutex_t mutex)
{
	if (pthread_mutex_lock(&mutex))
		error_msg(LOCK_MUTEX_ERROR);
}

void	unlock_mutex(pthread_mutex_t mutex)
{
	if (pthread_mutex_unlock(&mutex))
		error_msg(LOCK_MUTEX_ERROR);
}
