/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:52:50 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/15 20:57:21 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include "../include/error_mutex.h"

void	handle_einval(t_opcode opcode)
{
	if (opcode == LOCK || opcode == UNLOCK)
		error_message("The value specified by mutex does not refer "
			"to an initialized mutex object.\n");
	else if (opcode == DESTROY)
		error_message("The value specified by mutex is invalid.\n");
	else if (opcode == INIT)
		error_message("The value specified by attr is invalid.\n");
	else if (opcode == CREATE)
		error_message("Invalid settings in attr.\n");
	else if (opcode == JOIN)
		error_message("thread is not a joinable thread, or another "
			"thread is already waiting to join with this thread.\n");
	else if (opcode == DETACH)
		error_message("thread is not a joinable thread.\n");
}

void	handle_eagain(t_opcode opcode)
{
	if (opcode == INIT)
		error_message("The system lacked the necessary resources "
			"(other than memory) to initialize another mutex.\n");
	else if (opcode == LOCK)
		error_message("The mutex could not be acquired because the "
			"maximum number of recursive locks for mutex has been "
			"exceeded.\n");
	else if (opcode == CREATE)
		error_message("Insufficient resources to create another thread.\n");
}

void	handle_enomem(t_opcode opcode)
{
	if (opcode == INIT)
		error_message("Insufficient memory exists to initialize the mutex.\n");
}

void	handle_eperm(t_opcode opcode)
{
	if (opcode == INIT)
		error_message("The caller does not have the privilege "
			"to perform the operation.\n");
	else if (opcode == UNLOCK)
		error_message("The current thread does not own the mutex.\n");
	else if (opcode == CREATE)
		error_message("No permission to set the scheduling policy "
			"and parameters specified in attr.\n");
}

void	handle_ebusy(t_opcode opcode)
{
	if (opcode == INIT)
		error_message("The implementation has detected an attempt to "
			"reinitialize the object referenced by mutex, a previously "
			"initialized, but not yet destroyed, mutex.\n");
	else if (opcode == DESTROY)
		error_message("The implementation has detected an attempt to "
			"destroy the object referenced by mutex while it is locked "
			"or referenced by another thread.\n");
}
