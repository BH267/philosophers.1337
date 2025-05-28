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

int	eating(t_philo *philo)
{
	takefork(philo);
	setlm(philo);
	printf("%lu %d is eating\n", getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tte, philo);
	putfork(philo);
	return (0);
}

int	sleeping(t_philo *philo)
{
	printf("%lu %d is sleeping\n", getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tts, philo);
	return (0);
}

int	thinking(t_philo *philo)
{
	printf("%lu %d is thinking\n", getime() - philo->st, philo->id);
	return (0);
}

void	*routine(void *philos)
{
	t_philo		*philo;
	pthread_t	th;

	philo = (t_philo *)philos;
	pthread_create(&th, NULL, monitor, philo);
	philo->forks = sem_open("forks", O_CREAT);
	philo->lm = sem_open("lm", O_CREAT);
	philo->dead = sem_open("dead", O_CREAT);
	while (1)
	{
		if (philo->nmeals == philo->gdata->nte)
			exit(2);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	pthread_join(th, NULL);
	return (NULL);
}
