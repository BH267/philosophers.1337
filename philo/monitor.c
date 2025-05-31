/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:31:34 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/18 12:43:17 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*dead(void)
{
	static int	dead;

	return (&dead);
}

void	printdead(t_philo *philo)
{
	if (readead(philo) == 1)
	{
		usleep(1000);
		printf(RED "%lu %d is dead\n" DEFULT, getime() - philo->st, philo->id);
	}
}

void	*monitor(void *philos)
{
	t_philo	*philo;
	int		i;
	int		lm;

	philo = (t_philo *)philos;
	while (!readead(philo))
	{
		i = 0;
		lm = 0;
		while (i++ < philo->gdata->np && philo->gdata->nte != -2)
		{
			if (readnm(philos) >= philo->gdata->nte)
				lm++;
			if (lm == philo->gdata->np)
				setdead(philo, 2);
		}
		if (getime() - philo->st - readlm(philo) > (size_t)philo->gdata->ttd)
			setdead(philo, 1);
		printdead(philo);
		philo = philo->next;
		usleep(500);
	}
	return (NULL);
}
