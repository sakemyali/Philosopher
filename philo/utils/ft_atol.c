/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:57:46 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/15 18:19:47 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_atol(const char *str)
{
	long	n;

	n = 0;
	str = input_validation(str);
	while (is_digit(*str))
		n = (n * 10) + (*str++ - '0');
	if (n > INT_MAX)
		error_message("The value is too big to run.\n");
	return (n);
}
