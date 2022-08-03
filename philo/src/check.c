/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:22:47 by rade-sar          #+#    #+#             */
/*   Updated: 2022/08/01 20:53:39 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_all(t_data *data)
{
	int	i;

	if (data->argc < 5 || data->argc > 6)
		error_msg(N_ARGS_ERROR);
	i = 0;
	while (++i != data->argc)
	{
		if (ft_atol(data->argv[i]) < 1)
			error_msg(ARG_ERROR);
	}
}
