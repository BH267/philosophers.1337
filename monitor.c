/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:31:34 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/18 12:43:17 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	readead(t_philo *philo)
{
	int	d;

	pthread_mutex_lock(philo->isdead);
	d = *(philo->dead);
	pthread_mutex_unlock(philo->isdead);
	return (d);
}

int	setdead(t_philo *philo, int d)
{
	pthread_mutex_lock(philo->isdead);
	*(philo->dead) = d;
	pthread_mutex_unlock(philo->isdead);
	return (d);
}

void	*monitor(void *philos)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)philos;
	while (philo->next)
	{
		i = 0;
		while (i < philo->gdata->np)
		{
			setdead(philo, 2);
			if (philo->nmeals < philo->gdata->nte)
				setdead(philo, 0);
		}
		if (getime() - philo->lastmeal > (size_t)philo->gdata->ttd)
		{
			setdead(philo, 1);
			printf(RED"time %d died\n", philo->id);
		}
		if (readead(philo))
			break ;
		philo = philo->next;
	}
	return (NULL);
}
