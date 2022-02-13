/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:48:41 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/13 04:39:58 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philos(t_info *param)
{
	int	i;
	int	*pid;

	i = 0;
	param->start_time = get_time();
	pid = malloc(sizeof(int) * param->numb_phil);

	if (!pid)
		exit(1);
	create_processes(param, pid);
	kill_processes(param, pid);
	free(pid);
}

int	main(int argc, char **argv)
{
	t_info	param;
	int		i;

	param.numb_phil = ft_atoi(argv[1]);
	param.time_to_die = ft_atoi(argv[2]);
	param.time_to_eat = ft_atoi(argv[3]);
	param.time_to_sleep = ft_atoi(argv[4]);
	if (param.numb_phil <= 0 || param.time_to_die <= 0 || param.time_to_sleep <= 0 || param.time_to_eat <= 0)
		return (1);
	if (argc == 6)
		param.num_times_phil_eat = ft_atoi(argv[5]);
	else
		param.num_times_phil_eat = -1;
	init_semaphores(&param);
	create_philos(&param);
	close_unlink_semas(&param);
	return (0);
}
