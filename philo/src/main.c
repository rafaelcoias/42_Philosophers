/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:22:15 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/10 22:12:36 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static t_philo	*add_philo(t_philo *last, int id, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		error_msg(MALLOC_ERROR);
	philo->id = id;
	philo->ate = 0;
	philo->death = 0;
	philo->last_meal = 0;
	philo->ate_all = 0;
	philo->last = last;
	philo->next = NULL;
	philo->data = data;
	return (philo);
}

static void	init_philo(t_data *data)
{
	t_philo	*philo;
	t_philo	*first;
	int		id;

	philo = add_philo(NULL, 1, data);
	data->t0 = get_time();
	if (pthread_mutex_init(&(data->fork[0]), NULL))
		error_msg(MUTEX_ERROR);
	if (pthread_create(&(philo->th), NULL, routine, philo))
		error_msg(THREAD_ERROR);
	first = philo;
	id = 1;
	while (++id <= data->n_philo)
	{
		philo->next = add_philo(philo, id, data);
		philo = philo->next;
		if (pthread_mutex_init(&(data->fork[id - 1]), NULL))
				error_msg(MUTEX_ERROR);
		if (pthread_create(&(philo->th), NULL, routine, philo))
			error_msg(THREAD_ERROR);
	}
	philo->next = first;
	first->last = philo;
	data->philo = first;
}

static void	init_all(t_data *data)
{
	data->n_philo = ft_atol(data->argv[1]);
	data->t_die = ft_atol(data->argv[2]);
	data->t_eat = ft_atol(data->argv[3]);
	data->t_sleep = ft_atol(data->argv[4]);
	data->n_eat = 0;
	data->all_ate = 0;
	data->end = 0;
	data->t0 = 0;
	if (data->argv[5])
		data->n_eat = ft_atol(data->argv[5]);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->fork)
		error_msg(MALLOC_ERROR);
	if (data->n_philo == 1)
	{
		data->philo = add_philo(NULL, 1, data);
		do_one_philo(data);
		return ;
	}
	if (pthread_mutex_init(&(data->logs), NULL))
		error_msg(MUTEX_ERROR);
	if (pthread_mutex_init(&(data->check_death), NULL))
		error_msg(MUTEX_ERROR);
	init_philo(data);
	if (pthread_create(&(data->th), NULL, check_end, data))
		error_msg(THREAD_ERROR);
}

static void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	if (data->n_philo == 1)
	{		
		if (pthread_join(data->philo->th, NULL))
			error_msg(JOIN_THREAD);
		return ;
	}
	while (i != data->n_philo)
	{
		if (pthread_join(data->philo->th, NULL))
			error_msg(JOIN_THREAD);
		data->philo = data->philo->next;
		i++;
	}
	if (pthread_join(data->th, NULL))
		error_msg(JOIN_THREAD);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.argv = argv;
	data.argc = argc;
	check_all(&data);
	init_all(&data);
	join_threads(&data);
	end_simulation(&data);
	return (0);
}
