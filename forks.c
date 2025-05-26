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
