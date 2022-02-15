/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_forks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:49:32 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/15 03:28:22 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_info *args, int i)
{
	args->philo[i].id = i + 1;
	args->philo[i].r_fork = i;
	if (i == 0)
		args->philo[i].l_fork = args->num_of_phil - 1;
	else
		args->philo[i].l_fork = i - 1;
	args->philo[i].main_struct = args;
	args->philo[i].times_ph_ate = 0;
	args->philo[i].time_last_eat = get_time();
}

void	init_mutexs_and_philos(t_info *args)
{
	int	i;

	i = 0;
	while (i < args->num_of_phil)
	{
		if (pthread_mutex_init(&args->forks[i], NULL) != 0)
		{
			printf("failed to init mutex");
			free_and_destroy(args);
			break ;
		}
		create_philo(args, i);
		i++;
	}
}

int	create_p_f(t_info *args)
{
	args->philo = malloc(sizeof(t_philos) * args->num_of_phil);
	if (!args->philo)
		return (1);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->num_of_phil);
	if (!args->forks)
	{
		free(args->philo);
		return (1);
	}
	args->print_mtx = malloc(sizeof(pthread_mutex_t) * 1);
	if (!args->print_mtx)
	{
		free(args->print_mtx);
		return (1);
	}
	init_mutexs_and_philos(args);
	return (0);
}
