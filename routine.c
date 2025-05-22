/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:17:06 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/16 16:24:20 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->lfork));
	printf("%lu %d has taken a fork\n", getime() - philo->st, philo->id);
	pthread_mutex_lock(&(philo->rfork));
	printf("%lu %d has taken a fork\n", getime() - philo->st, philo->id);
	printf(RED"%lu %d is eating\n"DEFULT, getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tte);
	philo->nmeals += 1;
	philo->lastmeal = getime() - philo->st;
	pthread_mutex_unlock(&(philo->rfork));
	printf(GREEN"%lu %d has puting a fork\n"DEFULT, getime() - philo->st, philo->id);
	pthread_mutex_unlock(&(philo->lfork));
	printf(GREEN"%lu %d has puting a fork\n"DEFULT, getime() - philo->st, philo->id);
}

void	sleeping(t_philo *philo)
{
	printf("%lu %d is sleeping\n", getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tts);
}

void	thinking(t_philo *philo)
{
	printf("%lu %d is thinking\n", getime() - philo->st, philo->id);
}

void	*routine(void *philos)
{
	t_philo *philo;

	philo = (t_philo *)philos;
	while (1)
	{
		if (*(philo->dead))
			break ;
	//printf(BLUE" dead flag %d\n"DEFULT, *(philo->dead));
		thinking(philo);
		if (*(philo->dead))
			break ;
		if (philo->id % 2 == 0)
			eating(philo);
		else
		{
			hb_usleep(600);
			eating(philo);
		}
		if (*(philo->dead))
			break ;
		sleeping(philo);
		if (*(philo->dead))
			break ;
	}
	return (NULL);
}
