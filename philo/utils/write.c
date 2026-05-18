/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:35:50 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/18 17:57:44 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void write_debug(t_philo_status philo_status, t_philo *philo, long elapsed)
{
	if (philo_status == TAKE_FIRST_FORK && !simulation_end(philo->table))

}

void	write_philo_status(t_philo_status philo_status, t_philo *philo, bool debug)
{
	long elapsed;

	elapsed = get_time(MILLISECOND) - philo->table->start_simulation;
	if (philo->full)
		return ;
	ft_mutex(&philo->table->write_mutex, LOCK);
	if (debug)
		write_debug(philo_status, philo, elapsed);
	else
	{
		if ((philo_status == TAKE_FIRST_FORK || philo_status == TAKE_SECOND_FORK)
			&& !simulation_end(philo->table))
			printf(BWHT"%-6ld"RST" %d has taken the fork.\n", elapsed, philo->id);
		else if ((philo_status == EATING && !simulation_end(philo->table))
			printf(BWHT"%-6ld"BCYN" %d is eating.\n"RST, elapsed, philo->id);
		else if ((philo_status == SLEEPING && !simulation_end(philo->table))
			printf(BWHT"%-6ld"RST" %d is sleeping.\n", elapsed, philo->id);
		else if ((philo_status == THINKING && !simulation_end(philo->table))
			printf(BWHT"%-6ld"RST" %d is thinking.\n", elapsed, philo->id);
		else if ((philo_status == DIED && !simulation_end(philo->table))
			printf(BRED"%-6ld %d died.\n"RST, elapsed, philo->id);
	}
	ft_mutex(&philo->table->write_mutex, UNLOCK);
}
