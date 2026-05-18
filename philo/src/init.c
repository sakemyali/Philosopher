/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:07:21 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/18 17:37:41 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static void	assign_fork(t_philo *philo, t_fork *forks, int position)
{
	int	philo_n;

	philo_n = philo->table->philo_n;
	if (!(philo->id % 2))
	{
		philo->fork1 = &forks[(position + 1) % philo_n];
		philo->fork2 = &forks[position];
	}
	else if (philo->id % 2)
	{
		philo->fork1 = &forks[position];
		philo->fork2 = &forks[(position + 1) % philo_n];
	}

}

static void	philo_init(t_table *table)
{
	size_t	i;
	t_philo *philo;

	i = 0;
	while (i++ < table->philo_n)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;


	}
}

void	data_init(t_table *table)
{
	size_t	i;

	i = 0;
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->philo_n);
	ft_mutex(&table->table_mutex, INIT);
	ft_mutex(&table->write_mutex, INIT);
	table->forks = (t_fork *)malloc(sizeof(t_fork) * table->philo_n);
	while (i++ < table->philo_n)
	{
		ft_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}
