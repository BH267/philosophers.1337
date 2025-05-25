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

int	eating(t_philo *philo)
{
	if (readead(philo))
		return (1);
	takefork(philo);
	setlm(philo);
	printf("%lu %d is eating\n", getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tte, philo);
	putfork(philo);
	philo->nmeals += 1;
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (readead(philo))
		return (1);
	printf("%lu %d is sleeping\n", getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tts, philo);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (readead(philo))
		return (1);
	printf("%lu %d is thinking\n", getime() - philo->st, philo->id);
	//hb_usleep((philo->gdata->ttd - readlm(philo)) * 0.7, philo);
	return (0);
}

void	*routine(void *philos)
{
	t_philo *philo;

	philo = (t_philo *)philos;
	while (1)
	{
		if (readead(philo))
			break ;
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}
