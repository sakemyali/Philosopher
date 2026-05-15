/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:12:26 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/14 15:23:16 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdbool.h>
#include <stdlib.h>

static inline bool is_digit(char c)
{
    return(c >= '0' && c <= '9');
}

static inline bool is_space(char c)
{
    return((c >= 9 && c <= 13) || c == 32);
}

static const char input_validation(const char *str)
{
    size_t      len;
    const char  *number;

    len = 0;
    while (is_space(*str))
        str++;
    if (str == '+')
        str++;
    else if()

    
}