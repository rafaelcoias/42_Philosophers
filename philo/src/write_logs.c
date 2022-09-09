/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:02:58 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/09 00:37:06 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	write_logs(int philo, char *log, t_data *data)
{
	char	*color;

	if (data->end)
		return ;
	pthread_mutex_lock(&data->mutex);
	color = YELLOW;
	if (!ft_strcmp(log, DIED))
		color = RED;
	if (!ft_strcmp(log, EATING))
		color = GREEN;
	printf("%s%lli ms%s | %sPhilo %i %s\n", BLUE,
		  get_time() - data->t0, RESET, color, philo, log);
	printf(RESET);
	pthread_mutex_unlock(&data->mutex);
}
