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
	if (readead(philo))
		return (1);
	takefork(philo);
	setlm(philo);
	print(EAT, philo);
	hb_usleep(philo->gdata->tte, philo);
	putfork(philo);
	philo->nmeals += 1;
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (readead(philo))
		return (1);
	print(SLEEP, philo);
	hb_usleep(philo->gdata->tts, philo);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (readead(philo))
		return (1);
	print(THINK, philo);
	//hb_usleep((philo->gdata->ttd - readlm(philo)) * 0.7, philo);
	return (0);
}

void	*routine(void *philos)
{
	t_philo *philo;

	philo = (t_philo *)philos;
	while (1)
	{
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}
