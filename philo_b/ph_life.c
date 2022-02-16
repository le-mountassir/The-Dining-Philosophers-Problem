/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:11:35 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/15 03:12:26 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	newborn_philo(t_info *param, int i)
{
	t_philos	philo;

	philo.dead_phil = 0;
	philo.main_struct = param;
	philo.num_times_phil_eat = 0;
	philo.id = i + 1;
	philo.time_last_eat = get_time();
	pthread_create(&philo.thread, NULL, (void *)check_death, &philo);
	breathing(&philo);
	pthread_detach(philo.thread);
	exit(0);
}

void	think_sleep(t_philos *philo)
{
	if (philo->num_times_phil_eat != philo->main_struct->num_times_phil_eat)
	{
		sem_wait(philo->main_struct->print_sema);
		printf("time : %lu | %d is sleeping\n",
			get_time() - philo->main_struct->start_time, philo->id);
		sem_post(philo->main_struct->print_sema);
		wait_for(philo->main_struct->time_to_sleep);
		sem_wait(philo->main_struct->print_sema);
		printf("time : %lu | %d is thinking\n",
			get_time() - philo->main_struct->start_time, philo->id);
		sem_post(philo->main_struct->print_sema);
	}
}

void	breathing(t_philos *philo)
{
	while (!philo->dead_phil
		&& philo->num_times_phil_eat != philo->main_struct->num_times_phil_eat)
	{
		sem_wait(philo->main_struct->fork);
		sem_wait(philo->main_struct->print_sema);
		printf("time : %lu | %d has taken a fork\n",
			get_time() - philo->main_struct->start_time, philo->id);
		sem_post(philo->main_struct->print_sema);
		sem_wait(philo->main_struct->fork);
		sem_wait(philo->main_struct->print_sema);
		printf("time : %lu | %d has taken a fork\n",
			get_time() - philo->main_struct->start_time, philo->id);
		sem_post(philo->main_struct->print_sema);
		sem_wait(philo->main_struct->print_sema);
		printf("time : %lu | %d is eating\n",
			get_time() - philo->main_struct->start_time, philo->id);
		sem_post(philo->main_struct->print_sema);
		wait_for(philo->main_struct->time_to_eat);
		sem_post(philo->main_struct->fork);
		sem_post(philo->main_struct->fork);
		philo->num_times_phil_eat++;
		philo->time_last_eat = get_time();
		think_sleep(philo);
	}
}
