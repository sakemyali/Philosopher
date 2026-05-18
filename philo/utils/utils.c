/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:56:40 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/18 17:35:03 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

inline bool is_digit(char c) return (c >= '0' && c <= '9');

inline bool is_space(char c) return ((c >= 9 && c <= 13) || c == 32);

void spin_lock(t_table *table)
{
    while (!get_bool(&table->table_mutex, &table->all_threads_ready))
        ;
}

long    get_time(t_time_code time_code)
{
    struct timeval  timeval;
    if (gettimeofday(&timeval, NULL))
        error_message("gettimeofday failed.\n");
    if (time_code == SECOND)
        return (timeval.tv_sec + (timeval.tv_usec / 1e6));
    else if (time_code == MILLISECOND)
        return ((timeval.tv_sec * 1e3) + (timeval.tv_usec / 1e3));
    else if (time_code == MICROSECOND)
        return ((timeval.tv_sec * 1e6) + timeval.tv_usec);
    else
        error_message("Wrong input to gettime!\n");
    return (27);
}

void    ft_usleep(long usec, t_table *table)
{
    long    start;
    long    elapsed;
    long    remaining;

    start = get_time(MICROSECOND);
    while(get_time(MICROSECOND) - start < usec)
    {
        if (simulation_end(table))
            break;
        elapsed = get_time(MICROSECOND) - start;
        remaining = usec - elapsed;
        if (remaining > 1e3)
            u_sleep(usec / 2);
        else
        {
            while (get_time(MICROSECOND) - start < usec)
                ;
        }
    }
}
