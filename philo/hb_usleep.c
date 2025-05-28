/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:00 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/16 15:39:08 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	getime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (printf("gettimeofday : %s\n", strerror(errno)), 1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	hb_usleep(size_t sleep, t_philo *philo)
{
	size_t	ctime;

	ctime = getime();
	if (ctime == 1)
		return ;
	while ((getime() - ctime) < sleep)
	{
		if (readead(philo))
			return ;
		usleep(100);
	}
}

void	print(int state, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (state == EAT)
		printf("%lu %d is eating\n", getime() - philo->st, philo->id);
	else if (state == SLEEP)
		printf("%lu %d is sleeping\n", getime() - philo->st, philo->id);
	else if (state == THINK)
		printf("%lu %d is thinking\n", getime() - philo->st, philo->id);
	else if (state == DEAD)
		printf(RED "%lu %d is dead\n" DEFULT, getime() - philo->st, philo->id);
	pthread_mutex_unlock(philo->print);
}
