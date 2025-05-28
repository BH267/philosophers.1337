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
	if (philo->id % 2 != 0)
		usleep(500);
	sem_wait(philo->forks);
	sem_wait(philo->forks);
	printf("%lu %d has taken a fork\n", getime() - philo->st, philo->id);
}

void	putfork(t_philo *philo)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
}
