/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:49:16 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/14 21:09:49 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_semaphores(t_info *param)
{
	sem_unlink("sims");
	sem_unlink("dead_philo");
	sem_unlink("print_sema");
	param->fork = sem_open("sims", O_CREAT, 0700, param->numb_phil);
	if (param->fork == SEM_FAILED)
	{
		sem_close(param->fork);
		exit(1);
	}
	param->death_sema = sem_open("dead_philo", O_CREAT, 0700, 1);
	if (param->death_sema == SEM_FAILED)
	{
		sem_close(param->death_sema);
		exit(1);
	}
	param->print_sema = sem_open("print_sema", O_CREAT, 0700, 1);
	if (param->death_sema == SEM_FAILED)
	{
		sem_close(param->death_sema);
		exit(1);
	}
}

void	close_unlink_semas(t_info *param)
{
	if (param->fork)
	{
		sem_close(param->fork);
		sem_unlink("sims");
	}
	if (param->death_sema)
	{
		sem_close(param->death_sema);
		sem_unlink("dead_philo");
	}
	if (param->print_sema)
	{
		sem_close(param->print_sema);
		sem_unlink("print_sema");
	}
	exit(1);
}
