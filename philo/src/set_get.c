/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:27:17 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/18 16:37:27 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *dst, bool value)
{
	ft_mutex(mutex, LOCK);
	*dst = value;
	ft_mutex(mutex, UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	res;

	ft_mutex(mutex, LOCK);
	res = *value;
	ft_mutex(mutex, UNLOCK);
	return (res);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	res;

	ft_mutex(mutex, LOCK);
	res = *value;
	ft_mutex(mutex, UNLOCK);
	return (res);
}

void	set_long(pthread_mutex_t *mutex, long *dst, long value)
{
	ft_mutex(mutex, LOCK);
	*dst = value;
	ft_mutex(mutex, UNLOCK);
}

bool	simulation_end(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
