/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:43:53 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/16 23:46:51 by mosakura         ###   ########.fr       */
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
}

void simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;

	wait_all_threads(philo->table);

	
	return ;
}
