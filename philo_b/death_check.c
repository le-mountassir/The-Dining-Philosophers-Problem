/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:00:10 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/15 04:55:47 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	red_color(void)
{
	printf("\033[0;31m");
}

void	*check_death(t_philos *philo)
{
	unsigned long	now_time;

	while (1)
	{
		now_time = get_time();
		if (philo->num_times_phil_eat == philo->main_struct->num_times_phil_eat)
			return (NULL);
		if (now_time - philo->time_last_eat
			>= (unsigned long)philo->main_struct->time_to_die)
		{
			philo->dead_phil = 1;
			sem_wait(philo->main_struct->print_sema);
			red_color();
			printf("--DEATH--\nPhilosopher : %d just died\ntime : %lu\n", philo->id,
				now_time - philo->main_struct->start_time);
			exit(1);
		}
		usleep(500);
	}
	return (NULL);
}
