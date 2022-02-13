/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:49:16 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/13 04:16:58 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_semaphores(t_info *param)
{
	sem_unlink("sims");
	param->fork = sem_open("sims", O_CREAT,0700, param->numb_phil);
	if (param->fork == SEM_FAILED)
	{
		sem_close(param->fork);
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
}
