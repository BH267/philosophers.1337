/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:09:06 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/28 15:10:24 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_philo *philo, int e)
{
	/*int	i;

	i = 0;
	while (i < philo->gdata->np)
	{
		kill(philo->philo, SIGINT);
		i++;
	}*/
	hb_clearphilo(&(philo));
	exit(e);
}
