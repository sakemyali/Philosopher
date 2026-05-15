/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mutex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:53:24 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/15 20:57:35 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MUTEX_H
# define ERROR_MUTEX_H

# include <error.h>

void	handle_einval(t_opcode opcode);
void	handle_eagain(t_opcode opcode);
void	handle_enomem(t_opcode opcode);
void	handle_eperm(t_opcode opcode);
void	handle_ebusy(t_opcode opcode);
void	handle_edeadlk(t_opcode opcode);
void	handle_esrch(t_opcode opcode);

#endif
