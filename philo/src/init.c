/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:07:21 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/15 23:13:17 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static void philo_init(t_table *table)
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
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->philo_n);
	table->forks = (t_fork *)malloc(sizeof(t_fork) * table->philo_n);
}
