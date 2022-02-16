/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:48:49 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/14 21:09:23 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct philosophers
{
	pthread_t			thread;
	int					id;
	int					num_times_phil_eat;
	int					dead_phil;
	int					pid;
	unsigned long		time_last_eat;
	struct arguments	*main_struct;
}				t_philos;

typedef struct arguments
{
	unsigned long	start_time;
	int				numb_phil;
	int				*pid;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_phil_eat;
	t_philos		*philo;
	sem_t			*fork;
	sem_t			*death_sema;
	sem_t			*print_sema;
}				t_info;

int				check_param(t_info *param);
int				read_argv(char **argv, t_info *param, int argc);
void			init_semaphores(t_info *param);
void			close_unlink_semas(t_info *param);

unsigned long	get_time(void);
void			wait_for(int time_to_wait);

void			create_processes(t_info *param, int *pid);
void			kill_processes(t_info *param);
void			create_philos(t_info *param);

int				ft_atoi(const char *str);

void			*check_death(t_philos *philo);
void			breathing(t_philos *philo);
void			newborn_philo(t_info *param, int i);

#endif
