/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:29:02 by rade-sar          #+#    #+#             */
/*   Updated: 2022/08/03 17:15:29 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/* INCLUDES */

# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>

/* COLORS */

# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

/* DEFINES */

# define TRUE 1
# define FALSE 0
# define FORK_TAKEN "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

/* ERRORS */

# define N_ARGS_ERROR "Wrong numbers of arguments."
# define ARG_ERROR "Invalid argument."
# define MALLOC_ERROR "Malloc error."

/* LISTS */

typedef struct s_philo {
	int				id;
	int				eat;
	int				sleep;
	int				think;
	int				fork;
	int				death;
	struct s_philo	*last;
	struct s_philo	*next;
}	t_philo;

typedef struct s_data {
	char		**argv;
	int		argc;
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_eat;
	t_philo	*philo;
}	t_data;

/* FUNCTIONS */

void	check_all(t_data *data);
void	error_msg(char *str);
void	write_log(int time, int philo, char *log);
void	start_simulation(t_data *data);

/* UTILS */

size_t		ft_strlen(const char *str);
long long	ft_atol(const char *str);

#endif
