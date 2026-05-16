/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:25:24 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/16 22:30:53 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> //printf
# include <unistd.h> // usleep, fork
# include <stdlib.h> //malloc, free
# include <pthread.h> //mutex, threads
# include <sys/time.h> //gettimeofday
# include <stdbool.h>
# include <limits.h> //INTMAX
# include <errno.h> //EINVAL

# define RST  "\033[0m"		/* reset */
# define BBLK "\033[1;30m"  /* bold black   */
# define BRED "\033[1;31m"  /* bold red     */
# define BGRN "\033[1;32m"  /* bold green   */
# define BYEL "\033[1;33m"  /* bold yellow  */
# define BBLU "\033[1;34m"  /* bold blue    */
# define BMAG "\033[1;35m"  /* bold magenta */
# define BCYN "\033[1;36m"  /* bold cyan    */
# define BWHT "\033[1;37m"  /* bold white   */

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_opcode;

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
	t_fork		*fork1;
	t_fork		*fork2;
	pthread_t	thread_id;
	t_table		*table;
}				t_philo;

struct s_table
{
	long	philo_n;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	n_limit_meals;
	long	start_simulation;
	bool	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
};

void		error_message(char *error);
const char	input_validation(const char *str);
inline bool		is_space(char c);
inline bool		is_digit(char c);
long		ft_atol(const char *str);
void	mutex_error(int status, t_opcode opcode);
void	ft_thread(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode);
void	ft_mutex(pthread_mutex_t *mutex, t_opcode opcode);
void    parse_input(t_table *table, char **argv);
void	data_init(t_table *table);

#endif
