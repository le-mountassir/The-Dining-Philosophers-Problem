/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:50:20 by ahel-mou          #+#    #+#             */
/*   Updated: 2022/02/15 03:17:52 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct philosophers
{
	pthread_t			thread;
	int					id;
	int					times_ph_ate;
	int					r_fork;
	int					l_fork;
	unsigned long		time_last_eat;
	struct arguments	*main_struct;
}				t_philos;

typedef struct arguments
{
	unsigned long	start_time;
	int				num_of_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_phil_eat;
	int				dead_phil;
	t_philos		*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_mtx;
}				t_info;

void			init_phil(t_info *param, int i);
int				create_p_f(t_info *param);
int				chech_death(t_info *param);
void			breathing(t_philos *philo);
void			free_and_destroy(t_info *args);

unsigned long	get_time(void);
void			wait_for(int time_to_wait);

int				ft_atoi(const char *str);
#endif
