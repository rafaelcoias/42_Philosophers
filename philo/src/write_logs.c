/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:02:58 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/12 22:48:03 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	write_logs(int philo, char *log, t_data *data)
{
	char	*color;

	color = YELLOW;
	if (!ft_strcmp(log, DIED))
		color = RED;
	if (!ft_strcmp(log, EATING))
		color = GREEN;
	lock_mutex(data->check_end);
	if (data->end)
	{
		unlock_mutex(data->check_end);
		return ;
	}
	unlock_mutex(data->check_end);
	lock_mutex(data->logs);
	printf("%s%lli ms%s | %sPhilo %i %s\n", BLUE,
		get_time(data->t0), RESET, color, philo, log);
	printf(RESET);
	unlock_mutex(data->logs);
}

void	error_msg(char *str)
{
	write(2, RED, 7);
	write(2, "Error\n", 7);
	write(2, RESET, 4);
	write(2, str, ft_strlen(str));
	exit(1);
}
