/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:52:22 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/13 18:01:18 by rade-sar         ###   ########.fr       */
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
	lock_mutex(&(data->fork[i]));
	write_logs(philo->id, R_FORK_TAKEN, data);
	lock_mutex(&(data->fork[philo->id - 1]));
	write_logs(philo->id, L_FORK_TAKEN, data);
	lock_mutex(&data->check_lastmeal);
	philo->last_meal = get_time(data->t0);
	unlock_mutex(&data->check_lastmeal);
	write_logs(philo->id, EATING, data);
	usleep(data->t_eat * 1000);
	unlock_mutex(&(data->fork[i]));
	unlock_mutex(&(data->fork[philo->id - 1]));
	philo->ate++;
	if (data->n_eat && data->n_eat == philo->ate)
	{
		philo->ate_all = 1;
		lock_mutex(&data->check_all_ate);
		data->all_ate++;
		unlock_mutex(&data->check_all_ate);
	}
}

static int	check_death(t_data *data)
{
	int	i;

	lock_mutex(&data->check_end);
	i = data->end;
	unlock_mutex(&data->check_end);
	if (i)
		return (0);
	return (1);
}

void	*routine(void *p)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)p;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(10 * 1000);
	while (check_death(data))
	{
		eat(data, philo);
		if (philo->ate_all)
			break ;
		write_logs(philo->id, SLEEPING, data);
		usleep(data->t_sleep * 1000);
		write_logs(philo->id, THINKING, data);
	}
	return (NULL);
}
