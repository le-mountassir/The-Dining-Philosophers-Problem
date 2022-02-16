/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:48:41 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/14 21:09:08 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philos(t_info *param)
{
	int	i;

	i = 0;
	param->start_time = get_time();
	param->pid = malloc(sizeof(int) * param->numb_phil);
	if (!param->pid)
		exit(1);
	create_processes(param, param->pid);
	waitpid(-1, 0, 0);
	kill_processes(param);
	close_unlink_semas(param);
	free(param->pid);
}

int	main(int c, char **v)
{
	t_info	param;
	int		i;

	if (c != 5 && c != 6)
		return (1);
	param.numb_phil = ft_atoi(v[1]);
	param.time_to_die = ft_atoi(v[2]);
	param.time_to_eat = ft_atoi(v[3]);
	param.time_to_sleep = ft_atoi(v[4]);
	if (param.numb_phil <= 0 || param.time_to_die <= 0
		|| param.time_to_sleep <= 0 || param.time_to_eat <= 0)
		return (1);
	if (c == 6)
		param.num_times_phil_eat = ft_atoi(v[5]);
	else
		param.num_times_phil_eat = -1;
	init_semaphores(&param);
	create_philos(&param);
	return (0);
}
