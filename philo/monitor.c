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
	int		i;
	int		lm;

	philo = (t_philo *)philos;
	while (philo->next)
	{
		i = 0;
		lm = 0;
		while (i < philo->gdata->np && philo->gdata->nte != -1)
		{
			if (philo->nmeals >= philo->gdata->nte)
				lm++;
			if (lm == philo->gdata->np)
				setdead(philo, 2);
			i++;
		}
		if (getime() - philo->st - readlm(philo) > (size_t)philo->gdata->ttd)
			setdead(philo, 1);
		if (readead(philo))
			break ;
		philo = philo->next;
	}
	return (NULL);
}
