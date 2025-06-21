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
	if (philo->id % 2 != 0)
		usleep(500);
	sem_wait(philo->gdata->forks);
	sem_wait(philo->gdata->forks);
	if (!readead(philo))
	{
		putfork(philo);
		return (1);
	}
	printf("%lu %d has taken a fork\n", getime() - philo->st, philo->id);
	return (0);
}

void	putfork(t_philo *philo)
{
	sem_post(philo->gdata->forks);
	sem_post(philo->gdata->forks);
}
