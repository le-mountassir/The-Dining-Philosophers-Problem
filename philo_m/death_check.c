/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:17:33 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/15 04:49:23 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	red_color(void)
{
	printf("\033[0;31m");
}

int	chech_death(t_info *args)
{
	int				i;
	unsigned long	curr_time;

	while (1)
	{
		i = 0;
		while (i < args->num_of_phil)
		{
			if (args->philo[i].times_ph_ate == args->num_times_phil_eat)
				return (1);
			curr_time = get_time();
			if (curr_time - args->philo[i].time_last_eat
				> (unsigned long)args->time_to_die)
			{
				args->dead_phil = 1;
				red_color();
				pthread_mutex_lock(args->print_mtx);
				printf("--DEATH--\nPhilosopher : %d just died\ntime of death: %lu\n", args->philo->id,
					curr_time - args->start_time);
				return (1);
			}
			i++;
		}
		usleep(100);
	}
	return (0);
}
