/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:31:35 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/26 14:32:13 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	takefork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->lfork);
		pthread_mutex_lock(&(philo->rfork));
		if (print(FORK, philo))
		{
			putfork(philo);
			return (1);
		}
	}
	else
	{
		usleep(1000);
		pthread_mutex_lock(&(philo->rfork));
		pthread_mutex_lock(philo->lfork);
		if (print(FORK, philo))
		{
			putfork(philo);
			return (1);
		}
	}
	return (0);
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
