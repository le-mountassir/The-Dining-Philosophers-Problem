/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:49:10 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/13 04:36:40 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_on_error(t_info *param, int i, int *pid)
{
	while (i >= 0)
	{
		kill(pid[i], SIGKILL);
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
			kill_on_error(param, i, pid);
		if (pid[i] == 0)
			newborn_philo(param, i);
		i++;
	}
}

void	kill_processes(t_info *param, int *pid)
{
	int i = 0;
	while (i < param->numb_phil)
	{
		kill(pid[i], SIGKILL);
		i++;
	}
	exit(0);
}