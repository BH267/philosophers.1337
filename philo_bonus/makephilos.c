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
	sem_unlink("forks");
	sem_unlink("lm");
	sem_unlink("dead");
	sem_open("forks", O_CREAT, 0644, philo->gdata->np);
	sem_open("lm", O_CREAT, 0644, 1);
	sem_open("dead", O_CREAT, 0644, 1);
}

void	initphilos(t_philo *philos)
{
	int i;

	i = 0;
	while (i < philos->gdata->np)
	{
		philos->philo = fork();
		if (philos->philo == 0)
		{
			routine(philos);
			ft_exit(philos, 0) ;
		}
		philos = philos->next;
		i++;
	}
	i = 0;
	while (i < philos->gdata->np)
	{
		waitpid(philos->philo, NULL, 0);
		philos = philos->next;
		i++;
	}
}

t_philo	*makephilos(t_args *data)
{
	int				i;
	t_philo			*philos;

	philos = NULL;
	i = 0;
	while (i < data->np)
	{
		philoadd_back(&philos, newphilo(data));
		i++;
	}
	lastphilo(philos)->next = philos;
	initforks(philos);
	initphilos(philos);
	return (philos);
}
