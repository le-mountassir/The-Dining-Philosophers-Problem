/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:49:10 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/15 00:09:03 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_on_error(int i, t_info *param, int *pid)
{
	while (i >= 0)
	{
		kill(pid[i], SIGTERM);
		i--;
	}
	exit(1);
}

void	create_processes(t_info *param, int *pid)
{
	int	i;

	i = 0;
	while (i < param->numb_phil)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			kill_on_error(i, param, pid);
		if (pid[i] == 0)
			newborn_philo(param, i);
		i++;
	}
}

void	kill_processes(t_info *param)
{
	int	i;

	i = 0;
	while (i < param->numb_phil)
	{
		kill(param->pid[i], SIGTERM);
		i++;
	}
}
