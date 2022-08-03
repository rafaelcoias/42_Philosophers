/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:22:15 by rade-sar          #+#    #+#             */
/*   Updated: 2022/08/03 17:15:03 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_philo	*add_philo(t_philo *last, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		error_msg(MALLOC_ERROR);
	philo->id = id;
	philo->eat = 0;
	philo->sleep = 0;
	philo->think = 0;
	philo->death = 0;
	philo->last = last;
	philo->next = NULL;
	return (philo);
}

static void	init_philo(t_data *data)
{
	t_philo	*philo;
	t_philo	*first;
	int		id;

	philo = add_philo(NULL, 1);
	first = philo;
	id = 1;
	while (++id <= data->n_philo)
	{
		philo->next = add_philo(philo, id);
		philo = philo->next;
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
	if (data->argv[5])
		data->n_eat = ft_atol(data->argv[5]);
	init_philo(data);
}
/*
static void	print_philo(t_data *data)
{
	for (int i = 0; i < data->n_philo; i++)
	{
		printf("Philo %i , last is philo %i , next is philo %i \n",
			data->philo->id, data->philo->last->id, data->philo->next->id);
		data->philo = data->philo->next;
	}
}*/

int	main(int argc, char **argv)
{
	t_data	data;

	data.argv = argv;
	data.argc = argc;
	check_all(&data);
	init_all(&data);
	start_simulation(&data);
}
