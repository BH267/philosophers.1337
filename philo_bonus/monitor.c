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

	philo = (t_philo *)philos;
	while (readead(philo) != 0)
	{
		if (readnm(philo) >= philo->gdata->nte && philo->gdata->nte != -2)
			break ;
		if (getime() - philo->st - readlm(philo) > (size_t)philo->gdata->ttd)
		{
			setdead(philo);
			break ;
		}
		usleep(500);
	}
	return (NULL);
}
