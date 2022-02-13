/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:00:10 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/13 04:45:26 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(t_philos *philo)
{
	unsigned long	time_now;

	while (1)
	{
		time_now = get_time();
		if (philo->num_times_phil_eat == philo->main_struct->num_times_phil_eat)
			return (NULL);
		if (time_now - philo->time_last_eat >= (unsigned long)philo->main_struct->time_to_die)
		{
			philo->dead_phil = 1;
			printf("--DEATH--\nphilosopher %d has died | time : %lu\n",philo->id, time_now - philo->main_struct->start_time);
			return (NULL);
		}
		usleep(500);
	}
}
