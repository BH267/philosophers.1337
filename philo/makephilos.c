/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makephilos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:31:09 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/12 09:33:58 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initforks(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->gdata->np)
	{
		pthread_mutex_init(&(philos->rfork), NULL);
		philos->next->lfork = &(philos->rfork);
		philos = philos->next;
		i++;
	}
}

void	initphilos(t_philo *philos)
{
	int				i;
	pthread_t		th;
	pthread_mutex_t	isdead;

	pthread_mutex_init(&(isdead), NULL);
	i = 0;
	while (i < philos->gdata->np)
	{
		pthread_mutex_init(&(philos->lm), NULL);
		philos->isdead = &(isdead);
		pthread_create(philos->philo, NULL, routine, philos);
		philos = philos->next;
		i++;
	}
	pthread_create(&th, NULL, monitor, philos);
	i = 0;
	while (i < philos->gdata->np)
	{
		pthread_join(*(philos->philo), NULL);
		philos = philos->next;
		i++;
	}
	pthread_join(th, NULL);
}

t_philo	*makephilos(t_args *data)
{
	int				i;
	pthread_t		th[200];
	t_philo			*philos;
	pthread_mutex_t	forks[200];

	philos = NULL;
	i = 0;
	while (i < data->np)
	{
		philoadd_back(&philos, newphilo(&th[i], forks[i], data));
		i++;
	}
	lastphilo(philos)->next = philos;
	initforks(philos);
	initphilos(philos);
	return (philos);
}
