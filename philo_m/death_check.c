/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:17:33 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/17 19:47:11 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	chech_death(t_info *args)
{
	int				i;
	unsigned long	curr_time;

	while (1)
	{
		i = -1;
		while (++i < args->num_of_phil)
		{
			usleep(1000);
			if (args->philo[i].times_ph_ate == args->num_times_phil_eat)
				return (1);
			if (get_time() - args->philo[i].time_last_eat
				> (unsigned long)args->time_to_die)
			{
				args->dead_phil = 1;
				pthread_mutex_lock(args->print_mtx);
				printf("\033[0;31m%d died time: %lu\n",
					i + 1, get_time() - args->start_time);
				return (1);
			}
		}
	}
	return (0);
}
