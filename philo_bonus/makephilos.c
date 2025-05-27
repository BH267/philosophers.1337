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

void	initforks(t_philo *philo)
{
	philo->forks = sem_open("forks", O_CREAT);
	philo->lm = sem_open("lm", O_CREAT);
	philo->dead = sem_open("dead", O_CREAT);
}

void	initphilos(t_philo *philos)
{
	int				i;

	i = 0;
	while (i < philos->gdata->np)
	{
		philos->philo = fork();
		if (philos->philo == 0)
		{
			initforks(philos);
			routine(philos);
			return ;
		}
		philos = philos->next;
		i++;
	}
	i = 0;
	while (i < philos->gdata->np)
	{
		waitpid(philos->philo, NULL , 0);
		philos = philos->next;
		i++;
	}
}

t_philo	*makephilos(t_args *data)
{
	int				i;
	t_philo			*philos;

	sem_open("forks", O_CREAT, 0644, data->np);
	sem_open("lm", O_CREAT, 0644, 1);
	sem_open("dead", O_CREAT, 0644, 1);
	philos = NULL;
	i = 0;
	while (i < data->np)
	{
		philoadd_back(&philos, newphilo(data));
		i++;
	}
	lastphilo(philos)->next = philos;
	initphilos(philos);
	return (philos);
}
