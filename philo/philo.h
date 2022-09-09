/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:27:49 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/09 02:18:08 by rade-sar         ###   ########.fr       */
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
# include <sys/time.h>

/* COLORS */

# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[1;32m"
# define BLUE "\033[1;34m"
# define RESET	"\033[0m"

/* DEFINES */

# define TRUE 1
# define FALSE 0
# define R_FORK_TAKEN "has taken the right fork"
# define L_FORK_TAKEN "has taken the left fork"
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
# define JOIN_THREAD "Joining thread.\n"
# define DESTROY_MUTEX "Destroying mutex.\n"
# define TIME_ERROR "Getting time.\n"

/* LISTS */

typedef struct s_philo {
	int				id;
	int				ate;
	int				death;
	int				ate_all;
	long long		last_meal;
	pthread_t		th;
	struct s_philo	*last;
	struct s_philo	*next;
	struct s_data	*data;
}	t_philo;

typedef struct s_data {
	char					**argv;
	int					argc;
	int					n_philo;
	long long			t_die;
	long long			t_eat;
	long long			t_sleep;
	int					n_eat;
	int					all_ate;
	int					end;
	long long			t0;
	pthread_t			th;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*fork;
	t_philo				*philo;
}	t_data;

/* FUNCTIONS */

void	check_all(t_data *data);
void	error_msg(char *str);
void	write_logs(int philo, char *log, t_data *data);
void	end_simulation(t_data *data);
void	do_one_philo(t_data *data);
void	*routine(void *p);
void	*one_philo(void *p);
void	*check_end(void *d);

/* UTILS */

int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
long long	ft_atol(const char *str);
long long	get_time();

#endif
