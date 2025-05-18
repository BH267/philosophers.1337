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
	pthread_mutex_lock(&(philo->rfork));
	printf("time %d has taken a fork\n", philo->id);
	pthread_mutex_lock(&(philo->lfork));
	printf("time %d has taken a fork\n", philo->id);
	printf("time %d is eating\n", philo->id);
	hb_usleep(philo->gdata->tte);
	pthread_mutex_unlock(&(philo->rfork));
	pthread_mutex_unlock(&(philo->lfork));
}

void	sleeping(t_philo *philo)
{
	printf("time %d is sleeping\n", philo->id);
	hb_usleep(philo->gdata->tts);
}

void	thinking(t_philo *philo)
{
	printf("time %d is thinking\n", philo->id);
}

void	*routine(void *philos)
{
	t_philo *philo;

	philo = (t_philo *)philos;
	while (1)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}
