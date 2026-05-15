/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:12:26 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/15 18:41:54 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdbool.h>
#include <stdlib.h>

const char input_validation(const char *str)
{
    size_t      len;
    const char  *n;

    len = 0;
    while (is_space(*str))
        str++;
    if (str == '+')
        str++;
    else if (str == '-')
        error_message("Please only use positive numbers.\n");
    if (!is_digit(*str))
        error_message("Invalid intput, please enter valid digits.\n");
    n = str;
    while (is_digit(*str++))
        len++;
    if (len > 10)
        error_message("The value is too big to run.\n");
    return (n);
}

void    parse_input(t_table *table, char **argv)
{
    table->philo_n = ft_atol(argv[1]);
    table->time_to_die = ft_atol(argv[2]) * 1e3;
    table->time_to_eat = ft_atol(argv[3]) * 1e3;
    table->time_to_sleep = ft_atol(argv[4]) * 1e3;
    if (table->time_to_die < 6e4
        || table->time_to_eat < 6e4
        || table->time_to_sleep < 6e4)
        error_message("Time values cannot be below 60ms");
    if (argv[5])
        table->n_limit_meals = ft_atol(argv[5]);
    else
        table->n_limit_meals = -1;
}
