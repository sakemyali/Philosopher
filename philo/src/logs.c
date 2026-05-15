/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:49:28 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/14 16:03:03 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

inline void	p_taken_fork(int N, long time_stamp)
{
	printf("%ld %d has taken a fork\n", time_stamp, N);
}

inline void	p_eating(int N, long time_stamp)
{
	printf("%ld %d is eating\n", time_stamp, N);
}

inline void	p_sleeping(int N, long time_stamp)
{
	printf("%ld %d is sleeping\n", time_stamp, N);
}

inline void	p_thinking(int N, long time_stamp)
{
	printf("%ld %d is thinking\n", time_stamp, N);
}

inline void	p_died(int N, long time_stamp)
{
	printf("%ld %d  died\n", time_stamp, N);
}
