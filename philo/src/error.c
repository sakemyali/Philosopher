/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:25:55 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/15 20:59:04 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include "../include/philo.h"

void	mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL)
		handle_einval(opcode);
	else if (status == EAGAIN)
		handle_eagain(opcode);
	else if (status == ENOMEM)
		handle_enomem(opcode);
	else if (status == EPERM)
		handle_eperm(opcode);
	else if (status == EBUSY)
		handle_ebusy(opcode);
	else if (status == EDEADLK)
		handle_edeadlk(opcode);
	else if (status == ESRCH)
		handle_esrch(opcode);
}

void    error_message(char *error)
{
    printf("%s\n", error);
    exit(1);
}
