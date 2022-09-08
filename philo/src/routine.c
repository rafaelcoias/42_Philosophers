/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:52:22 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/08 06:04:12 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_death(t_data *data, t_philo *philo)
{
	if (get_time() - data->t0 - philo->last_meal > data->t_die)
	{
		philo->death = 1;
		data->end = 1;
		pthread_mutex_lock(&data->mutex);
		printf("%s%lli ms%s | %sPhilo %i %s\n", BLUE,
			get_time() - data->t0, RESET, RED, philo->id, DIED);
		pthread_mutex_unlock(&data->mutex);
		return (1);
	}
	return (0);
}

static void	eat(t_data *data, t_philo *philo)
{
	int	i;

	if (philo->id == data->n_philo)
		i = 0;		
	else
		i = philo->id;
	if (philo->last_meal && check_death(data, philo))
		return ;
	pthread_mutex_lock(&data->fork[i]);	
	write_logs(philo->id, R_FORK_TAKEN, data);
	pthread_mutex_lock(&data->fork[philo->id - 1]);	
	write_logs(philo->id, L_FORK_TAKEN, data);
	philo->last_meal = get_time() - data->t0;
	write_logs(philo->id, EATING, data);
	usleep(data->t_eat);
	pthread_mutex_unlock(&data->fork[i]);	
	pthread_mutex_unlock(&data->fork[philo->id - 1]);	
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
	usleep(10000);
	while (!philo->death && !data->end)
	{
		eat(data, philo);
		write_logs(philo->id, SLEEPING, data);	
		usleep(data->t_sleep);
		write_logs(philo->id, THINKING, data);
		usleep(1000);
	}
	return (NULL);
}
