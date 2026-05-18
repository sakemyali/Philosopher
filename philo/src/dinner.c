/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:43:53 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/18 17:57:57 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dinner(t_table *table)
{
	size_t	i;

	i = 0;
	if (table->n_limit_meals == 0)
		return ;
	else if (table->philo_n == 1)
	{

	}
	else
	{
		while (i++ < table->philo_n)
			ft_thread(&table->philos[i].thread_id, simulation(),
				&table->philos[i], CREATE);
	}
	table->start_simulation = get_time(MILLISECOND);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = 0;
	while (i++ < table->philo_n)
		ft_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
}

void simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;

	spin_lock(philo->table);
	while (condition)
	{
		/* code */
	}


	return ;
}
