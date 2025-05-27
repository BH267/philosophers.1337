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

	sem_wait(philo->dead);
	d = *(dead());
	sem_post(philo->dead);
	return (d);
}

int	setdead(t_philo *philo, int d)
{
	sem_wait(philo->dead);
	*(dead()) = d;
	if (d == 1)
	{
		print(DEAD, philo);
		exit(1);
	}
	sem_post(philo->dead);
	return (d);
}

size_t	readlm(t_philo *philo)
{
	size_t	d;

	sem_wait(philo->lm);
	d = philo->lastmeal;
	sem_post(philo->lm);
	return (d);
}

ssize_t	readnm(t_philo *philo)
{
	ssize_t	d;

	sem_wait(philo->lm);
	d = philo->lastmeal;
	sem_post(philo->lm);
	return (d);
}

void	setlm(t_philo *philo)
{
	sem_wait(philo->lm);
	philo->lastmeal = getime() - philo->st;
	philo->nmeals += 1;
	sem_post(philo->lm);
}
