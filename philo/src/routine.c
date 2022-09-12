/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:52:22 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/12 10:57:17 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	eat(t_data *data, t_philo *philo)
{
	int	i;

	if (philo->id == data->n_philo)
		i = 0;
	else
		i = philo->id;
	lock_mutex(data->fork[i]);
	write_logs(philo->id, R_FORK_TAKEN, data);
	lock_mutex(data->fork[philo->id - 1]);
	write_logs(philo->id, L_FORK_TAKEN, data);
	lock_mutex(data->check_end);
	philo->last_meal = get_time() - data->t0;
	unlock_mutex(data->check_end);
	write_logs(philo->id, EATING, data);
	usleep(data->t_eat * 1000);
	unlock_mutex(data->fork[i]);
	unlock_mutex(data->fork[philo->id - 1]);
	philo->ate++;
	if (data->n_eat && data->n_eat == philo->ate)
	{
		philo->ate_all = 1;
		lock_mutex(data->check_end);
		data->all_ate++;
		unlock_mutex(data->check_end);
	}
}

void	*routine(void *p)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)p;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(10000);
	while (1)
	{
		eat(data, philo);
		write_logs(philo->id, SLEEPING, data);
		usleep(data->t_sleep * 1000);
		write_logs(philo->id, THINKING, data);
		lock_mutex(data->check_end);
		if (data->end || philo->ate_all)
			break ;
		unlock_mutex(data->check_end);
	}
	unlock_mutex(data->check_end);
	return (NULL);
}
