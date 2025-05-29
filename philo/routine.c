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
	if (takefork(philo))
		return (1);
	setlm(philo);
	if (print(EAT, philo))
		return (1);
	hb_usleep(philo->gdata->tte, philo);
	putfork(philo);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (print(SLEEP, philo))
		return (1);
	hb_usleep(philo->gdata->tts, philo);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (print(THINK, philo))
		return (1);
	return (0);
}

void	*routine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (1)
	{
		if (philo ->gdata->nte != -2 && readnm(philo) == philo->gdata->nte)
			break;
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}
