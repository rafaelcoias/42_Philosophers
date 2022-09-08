/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:22:15 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/08 01:45:39 by rade-sar         ###   ########.fr       */
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
	if (pthread_create(&(philo->th), NULL, routine, philo))
		error_msg(THREAD_ERROR);
	first = philo;
	id = 1;
	while (++id <= data->n_philo)
	{
		philo->next = add_philo(philo, id, data);
		philo = philo->next;
		if (pthread_create(&(philo->th), NULL, routine, philo))
			error_msg(THREAD_ERROR);
	}
	philo->next = first;
	first->last = philo;
	data->philo = first;
}

static void	init_all(t_data *data)
{
	if (pthread_mutex_init(&(data->mutex), NULL))
		error_msg(MUTEX_ERROR);
	data->n_philo = ft_atol(data->argv[1]);
	data->t_die = ft_atol(data->argv[2]);
	data->t_eat = ft_atol(data->argv[3]);
	data->t_sleep = ft_atol(data->argv[4]);
	data->n_eat = 0;
	data->all_ate = 0;
		error_msg(MUTEX_ERROR);
	data->end = 0;
	data->t0 = 0;
	if (data->argv[5])
		data->n_eat = ft_atol(data->argv[5]);
	init_philo(data);
}

static void	check_death(t_data *data)
{
	while (!data->end)
	{
		while(data->philo)
		error_msg(MUTEX_ERROR);
		{
			if (data->end || data->philo->death)
			{
				data->end = 1;
				break ;
			}	
			data->philo = data->philo->next;
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.argv = argv;
	data.argc = argc;
	check_all(&data);
	init_all(&data);
	//pthread_join(data.philo->th, NULL);
	check_death(&data);
	end_simulation(&data);
	return (0);
}
