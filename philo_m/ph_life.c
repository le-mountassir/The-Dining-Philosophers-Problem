/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:53:30 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/16 04:31:34 by ahel-mou         ###   ########.fr       */
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
		pthread_mutex_lock(philo->main_struct->print_mtx);
		printf("time : %lu | %d is sleeping\n",
			get_time() - philo->main_struct->start_time, philo->id);
		pthread_mutex_unlock(philo->main_struct->print_mtx);
		wait_for(philo->main_struct->time_to_sleep);
		pthread_mutex_lock(philo->main_struct->print_mtx);
		printf("time : %lu | %d is thinking\n",
			get_time() - philo->main_struct->start_time, philo->id);
		pthread_mutex_unlock(philo->main_struct->print_mtx);
	}
}

void	breathing(t_philos *philo)
{
	while (!philo->main_struct->dead_phil && philo->times_ph_ate
		!= philo->main_struct->num_times_phil_eat)
	{
		pthread_mutex_lock(&philo->main_struct->forks[philo->r_fork]);
		pthread_mutex_lock(philo->main_struct->print_mtx);
		printf("time : %lu | %d has taken the right fork\n",
			get_time() - philo->main_struct->start_time, philo->id);
		pthread_mutex_unlock(philo->main_struct->print_mtx);
		pthread_mutex_lock(&philo->main_struct->forks[philo->l_fork]);
		pthread_mutex_lock(philo->main_struct->print_mtx);
		printf("time : %lu | %d has taken the left fork\n",
			get_time() - philo->main_struct->start_time, philo->id);
		pthread_mutex_unlock(philo->main_struct->print_mtx);
		pthread_mutex_lock(philo->main_struct->print_mtx);
		philo->time_last_eat = get_time();
		printf("time : %lu | %d is eating\n",
			get_time() - philo->main_struct->start_time, philo->id);
		pthread_mutex_unlock(philo->main_struct->print_mtx);
		wait_for(philo->main_struct->time_to_eat);
		put_forks_down(philo);
		sleep_or_think(philo);
		philo->times_ph_ate++;
	}
}
