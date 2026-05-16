/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:45:02 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/15 22:43:51 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_mutex(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
	else
		error_message("Wrong opcode for mutex handle.\n");
}

void	ft_thread(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		mutex_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		mutex_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		mutex_error(pthread_detach(*thread), opcode);
	else
		error_message("Wrong opcode for thread_handle: \nuse <CREATE> <JOIN> <DETACH>\n");
}