/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrire_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:02:58 by rade-sar          #+#    #+#             */
/*   Updated: 2022/08/03 16:10:52 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	write_log(int time, int philo, char *log)
{
	printf(YELLOW);
	printf("%i %i %s", time, philo, log);
	printf(RESET);
}
