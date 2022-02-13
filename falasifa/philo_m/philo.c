/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:50:13 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/07 13:13:07 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_destroy(t_info *args)
{
	int	i;

	free(args->forks);
	free(args->philo);
	i = 0;
	while (i < args->num_of_phil)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
}

static void	create_threads(t_info *args)
{
	int	i;

	i = 0;
	args->start_time = get_time();
	while (i < args->num_of_phil)
	{
		pthread_create(&args->philo[i].thread, NULL,
			(void *)breathing, &args->philo[i]);
		usleep(100);
		i += 2;
	}
	i = 1;
	while (i < args->num_of_phil)
	{
		pthread_create(&args->philo[i].thread, NULL,
			(void *)breathing, &args->philo[i]);
		usleep(100);
		i += 2;
	}
	if (chech_death(args))
		return ;
	i = -1;
	while (++i < args->num_of_phil)
		pthread_join(args->philo[i].thread, NULL);
}

int	main(int c, char **v)
{
	t_info	args;
	int		i;

	if (c != 5 && c != 6)
		return (1);
	args.num_of_phil = ft_atoi(v[1]);
	args.time_to_die = ft_atoi(v[2]);
	args.time_to_eat = ft_atoi(v[3]);
	args.time_to_sleep = ft_atoi(v[4]);
	if (args.num_of_phil <= 0 || args.time_to_die <= 0
		|| args.time_to_sleep <= 0 || args.time_to_eat <= 0)
	{
		printf("\033[0;31m error in the args\n");
		return (1);
	}
	args.dead_phil = 0;
	if (c == 6)
		args.num_times_phil_eat = ft_atoi(v[5]);
	else
		args.num_times_phil_eat = -1;
	if (create_p_f(&args))
		return (1);
	create_threads(&args);
	free_and_destroy(&args);
	return (0);
}
