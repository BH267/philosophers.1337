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
		philos->next->lfork = philos->rfork;
		philos = philos->next;
		i++;
	}
}

void	initphilos(t_philo *philos)
{
	int			i;
	pthread_t	th;

	i = 0;
	while (i < philos->gdata->np)
	{
		pthread_create(philos->philo, NULL, routine, philos);
		philos = philos->next;
		i++;
	}
	i = 0;
	while (i < philos->gdata->np)
	{
		pthread_join(*(philos->philo), NULL);
		philos = philos->next;
		i++;
	}
	pthread_create(&th, NULL, monitor, philos);
	pthread_join(th, NULL);
}

t_philo	*makephilos(t_args *data)
{
	int			i;
	pthread_t	th[data->np];
	t_philo		*philos;
	pthread_mutex_t	forks[data->np];

	//th = (pthread_t *)malloc(sizeof(pthread_t) * data->np);
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
