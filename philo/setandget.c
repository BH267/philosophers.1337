/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setandget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:33:43 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/26 14:34:24 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	readead(t_philo *philo)
{
	int	d;

	d = 0;
	pthread_mutex_lock(philo->isdead);
	d = *(dead());
	pthread_mutex_unlock(philo->isdead);
	return (d);
}

void	setdead(t_philo *philo, int d)
{
	pthread_mutex_lock(philo->isdead);
	*(dead()) = d;
	if (d == 1)
		print(DEAD, philo);
	pthread_mutex_unlock(philo->isdead);
}

size_t	readlm(t_philo *philo)
{
	size_t	d;

	d = 0;
	pthread_mutex_lock(&(philo->lm));
	d = philo->lastmeal;
	pthread_mutex_unlock(&(philo->lm));
	return (d);
}

ssize_t	readnm(t_philo *philo)
{
	ssize_t	d;

	d = 0;
	pthread_mutex_lock(&(philo->lm));
	d = philo->nmeals;
	pthread_mutex_unlock(&(philo->lm));
	return (d);
}

void	setlm(t_philo *philo)
{
	pthread_mutex_lock(&(philo->lm));
	philo->lastmeal = getime() - philo->st;
	philo->nmeals += 1;
	pthread_mutex_unlock(&(philo->lm));
}
