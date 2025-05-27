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

void	*monitor(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (!readead(philo))
	{
		if (readnm(philos) >= philo->gdata->nte)
			setdead(philo, 2);
		if (getime() - philo->st - readlm(philo) > (size_t)philo->gdata->ttd)
			setdead(philo, 1);
		if (readead(philo))
			break ;
	}
	return (NULL);
}
