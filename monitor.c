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

void	*monitor(void *philos)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)philos;
	while (philo->next)
	{
		if (getime() - philo->lastmeal > (size_t)philo->gdata->ttd)
		{
			*(philo->dead) = 1;
			printf(RED"time %d died\n", philo->id);
		}
		i = 0;
		while (i < philo->gdata->np)
		{
			*(philo->dead) = 2;
			if (philo->nmeals < philo->gdata->nte)
				*(philo->dead) = 0;
		}
		if (*(philo->dead))
			break ;
		philo = philo->next;
	}
	return (NULL);
}
