/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makephilos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:31:09 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/12 09:33:58 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*makephilos(int np)
{
	int		i;
	pthread_t	th[np];
	t_philo	*philos;

	philos = (t_philo*)malloc(sizeof(t_philo));
	i = 0;
	while (i < np)
	{
		philoadd_back(&philos, newphilo(&th[i]));
		i++;
	}
	lastphilo(philos)->next = philos;
	return (philos);
}
