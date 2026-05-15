/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:25:29 by mosakura          #+#    #+#             */
/*   Updated: 2026/05/14 16:26:55 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    if (argc == 5)
    {

    }
    else if (argc == 6)
    {

    }
    else
    {
        error_message("Invalid arguments, follow the example:\n./philo 200 800 800 [10]\n");
        return (1);
    }
}
