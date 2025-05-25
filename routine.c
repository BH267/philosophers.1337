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

void	takefork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->lfork);
		printf("%lu %d has taken a fork\n", getime() - philo->st, philo->id);
		pthread_mutex_lock(&(philo->rfork));
		printf("%lu %d has taken a fork\n", getime() - philo->st, philo->id);
	}
	else
	{
		pthread_mutex_lock(&(philo->rfork));
		printf("%lu %d has taken a fork\n", getime() - philo->st, philo->id);
		pthread_mutex_lock(philo->lfork);
		printf("%lu %d has taken a fork\n", getime() - philo->st, philo->id);
	}
}

void	putfork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(&(philo->rfork));
	}
	else
	{
		pthread_mutex_unlock(&(philo->rfork));
		pthread_mutex_unlock(philo->lfork);
	}
}

void	eating(t_philo *philo)
{
	takefork(philo);
	printf(RED"%lu %d is eating\n"DEFULT, getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tte);
	philo->nmeals += 1;
	putfork(philo);
	philo->lastmeal = getime() - philo->st;
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
		if (readead(philo))
			break ;
		printf(BLUE" dead flag %d\n"DEFULT, readead(philo));
		eating(philo);
		if (readead(philo))
			break ;
		sleeping(philo);
		if (readead(philo))
			break ;
		thinking(philo);
		if (readead(philo))
			break ;
	}
	return (NULL);
}
