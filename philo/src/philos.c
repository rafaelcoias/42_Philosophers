/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:52:45 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/12 22:50:18 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*one_philo(void *p)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)p;
	data = philo->data;
	printf("%s%lli ms%s | %sPhilo %i %s\n", BLUE,
		get_time(data->t0), RESET, YELLOW, 1, L_FORK_TAKEN);
	printf("%s%lli ms%s | %sPhilo %i %s\n", BLUE,
		get_time(data->t0), RESET, RED, 1, DIED);
	return (NULL);
}

void	do_one_philo(t_data *data)
{
	data->t0 = get_time(0);
	if (pthread_create(&(data->philo->th), NULL, one_philo, data->philo))
		error_msg(THREAD_ERROR);
}

t_philo	*add_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		error_msg(MALLOC_ERROR);
	philo->id = id;
	philo->ate = 0;
	philo->last_meal = 0;
	philo->ate_all = 0;
	philo->next = NULL;
	philo->data = data;
	return (philo);
}

void	create_philos(t_data *data)
{
	t_philo	*philo;
	t_philo	*first;
	int		id;

	if (data->n_philo == 1)
	{
		data->philo = add_philo(1, data);
		do_one_philo(data);
		return ;
	}
	philo = add_philo(1, data);
	first = philo;
	id = 1;
	while (++id <= data->n_philo)
	{
		philo->next = add_philo(id, data);
		philo = philo->next;
	}
	philo->next = first;
	first->last = philo;
	data->philo = first;
	create_mutexes(data);
	create_threads(data);
}
