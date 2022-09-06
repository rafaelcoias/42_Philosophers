/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:29:02 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/06 02:17:23 by rade-sar         ###   ########.fr       */
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
# include <pthread.h>
# include <time.h>

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

# define N_ARGS_ERROR "Wrong numbers of arguments.\n"
# define ARG_ERROR "Invalid argument.\n"
# define MALLOC_ERROR "Malloc error.\n"
# define MUTEX_ERROR "Creating mutex.\n"
# define THREAD_ERROR "Creating thread.\n"

/* LISTS */

typedef struct s_philo {
	int				id;
	int				ate;
	int				fork;
	int				death;
	int				last_meal;
	pthread_t		th;
	struct s_philo	*last;
	struct s_philo	*next;
	struct s_data	*data;
}	t_philo;

typedef struct s_data {
	char					**argv;
	int					argc;
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_eat;
	int					end;
	int					time;
	pthread_mutex_t	mutex;
	t_philo				*philo;
}	t_data;

/* FUNCTIONS */

void	check_all(t_data *data);
void	error_msg(char *str);
void	write_logs(int time, int philo, char *log, t_data *data);
void	end_simulation(t_data *data);

/* ROUTINE */

void	*routine(void *data);

/* UTILS */

size_t		ft_strlen(const char *str);
long long	ft_atol(const char *str);
int			ft_strcmp(const char *s1, const char *s2);

#endif
