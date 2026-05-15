/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:25:24 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/15 16:43:30 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PHILO_H
# define PHILO_H

# include <stdio.h> //printf
# include <unistd.h> // usleep, fork
# include <stdlib.h> //malloc, free
# include <pthread.h> //mutex, threads
# include <sys/time.h> //gettimeofday
# include <stdbool.h>
# include <limits.h> //INTMAX

typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}				t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}				t_philo;

struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	start_simulation;
	bool	end_simulatiosn;
	t_fork	*forks;
	t_philo	*philos;
};
#endif
