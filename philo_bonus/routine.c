/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:19:13 by habenydi          #+#    #+#             */
/*   Updated: 2025/06/19 19:31:14 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	if (philo->gdata->np < 100)
		usleep(200);
	if (philo->id % 2 == 0)
		usleep(500);
	takefork(philo);
	setlm(philo);
	philo->nmeals += 1;
	printf("%lu %d is eating\n", getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tte);
	putfork(philo);
	return (0);
}

int	sleeping(t_philo *philo)
{
	printf("%lu %d is sleeping\n", getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tts);
	return (0);
}

int	thinking(t_philo *philo)
{
	printf("%lu %d is thinking\n", getime() - philo->st, philo->id);
	return (0);
}

void	routine(t_philo *philo)
{
	pthread_t	th;

	philo->forks = sem_open("fork", O_CREAT);
	philo->lm = sem_open("lm", O_CREAT);
	philo->dead = sem_open("deadlock", O_CREAT);
	philo->mat = sem_open("dead", O_CREAT);
	pthread_create(&th, NULL, monitor, philo);
	while (1)
	{
		if (philo->nmeals <= philo->gdata->nte)
			exit(2);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	pthread_join(th, NULL);
}
