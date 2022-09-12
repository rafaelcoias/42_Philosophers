/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:57:32 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/12 10:39:25 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	join_threads(t_data *data)
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

void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	data->t0 = get_time();
	while (i != data->n_philo)
	{
		if (pthread_create(&(data->philo->th), NULL, routine, data->philo))
			error_msg(THREAD_ERROR);
		data->philo = data->philo->next;
		i++;
	}
	if (pthread_create(&(data->th), NULL, check_end, data))
		error_msg(THREAD_ERROR);
}