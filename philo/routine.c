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
	if (philo->gdata->np < 100)
		usleep(200);
	if (philo->id % 2 == 0)
		usleep(500);
	if (takefork(philo))
		return (1);
	setlm(philo);
	printf("%lu %d is eating\n", getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tte, philo);
	putfork(philo);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (readead(philo))
		return (1);
	printf("%lu %d is sleeping\n", getime() - philo->st, philo->id);
	hb_usleep(philo->gdata->tts, philo);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (readead(philo))
		return (1);
	printf("%lu %d is thinking\n", getime() - philo->st, philo->id);
	return (0);
}

void	*routine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (readead(philo) == 0)
	{
		if (readnm(philo) == philo->gdata->nte)
			break ;
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}
