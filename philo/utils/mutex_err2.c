/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_err2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:52:50 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/15 20:59:34 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include "../include/error_mutex.h"

void	handle_edeadlk(t_opcode opcode)
{
	if (opcode == LOCK)
		error_message("The current thread already owns the mutex.\n");
	else if (opcode == JOIN)
		error_message("A deadlock was detected, or the calling thread "
			"tried to join itself.\n");
}

void	handle_esrch(t_opcode opcode)
{
	if (opcode == JOIN || opcode == DETACH)
		error_message("No thread with the given ID could be found.\n");
}
