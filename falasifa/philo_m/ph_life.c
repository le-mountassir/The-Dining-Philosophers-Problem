/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:53:30 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/10 12:42:02 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_forks_down(t_philos *philo)
{
	pthread_mutex_unlock(&philo->main_struct->forks[philo->r_fork]);
	pthread_mutex_unlock(&philo->main_struct->forks[philo->l_fork]);
}

void	sleep_or_think(t_philos *philo)
{
	if (philo->times_ph_ate != philo->main_struct->num_times_phil_eat)
	{
		printf("philosopher %d is sleeping | time : %lu\n",
			philo->id, get_time() - philo->main_struct->start_time);
		wait_for(philo->main_struct->time_to_sleep);
		printf("philosopher %d is thinking | time : %lu\n",
			philo->id, get_time() - philo->main_struct->start_time);
	}
}

void	breathing(t_philos *philo)
{
	while (!philo->main_struct->dead_phil && philo->times_ph_ate
		!= philo->main_struct->num_times_phil_eat)
	{
		pthread_mutex_lock(&philo->main_struct->forks[philo->r_fork]);
		printf("philosopher %d has taken the right fork | time : %lu\n", philo->id,
			get_time() - philo->main_struct->start_time);
		pthread_mutex_lock(&philo->main_struct->forks[philo->l_fork]);
		printf("philosopher %d has taken the left fork | time : %lu\n", philo->id,
			get_time() - philo->main_struct->start_time);
		printf("philosopher %d is eating | time : %lu\n",
			philo->id, get_time() - philo->main_struct->start_time);
		wait_for(philo->main_struct->time_to_eat);
		philo->time_last_eat = get_time();
		put_forks_down(philo);
		sleep_or_think(philo);
		philo->times_ph_ate++;
	}
}
