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
	d = *(dead());
	pthread_mutex_unlock(philo->isdead);
	return (d);
}

int	setdead(t_philo *philo, int d)
{
	pthread_mutex_lock(philo->isdead);
	*(dead()) = d;
	if (d == 1)
		printf(RED"%lu %d died -> lastmeal: %lu\n"DEFULT, getime() - philo->st, philo->id, readlm(philo));
	pthread_mutex_unlock(philo->isdead);
	return (d);
}

size_t	readlm(t_philo *philo)
{
	size_t	d;

	pthread_mutex_lock(&(philo->lm));
	d = philo->lastmeal;
	pthread_mutex_unlock(&(philo->lm));
	return (d);
}

size_t	setlm(t_philo *philo)
{
	int	lm;

	pthread_mutex_lock(&(philo->lm));
	philo->lastmeal = getime() - philo->st;
	lm = philo->lastmeal;
	pthread_mutex_unlock(&(philo->lm));
	return (lm);
}

int	*dead(void)
{
	static int	dead;

	return (&dead);
}

void	*monitor(void *philos)
{
	t_philo	*philo;
	int		i;
	int		lm;

	philo = (t_philo *)philos;
	while (philo->next)
	{
		i = 0;
		lm = 0;
		while (i < philo->gdata->np && philo->gdata->nte != -1)
		{
			if (philo->nmeals >= philo->gdata->nte)
				lm++;
			if (lm == philo->gdata->np)
				setdead(philo, 2);
			i++;
		}
		if (readlm(philo) > (size_t)philo->gdata->ttd)
			setdead(philo, 1);
		if (readead(philo))
			break ;
		philo = philo->next;
	}
	return (NULL);
}
