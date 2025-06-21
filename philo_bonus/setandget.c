/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setandget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:33:43 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/26 14:34:24 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	readead(t_philo *philo)
{
	int	d;

	sem_wait(philo->gdata->dead);
	d = philo->gdata->mat->__align;
	sem_post(philo->gdata->dead);
	return (d);
}

int	setdead(t_philo *philo)
{
	sem_wait(philo->gdata->dead);
	philo->gdata->mat->__align = 0;
	usleep(1000);
	printf(RED"%lu %d is dead\n"DEFULT, getime() - philo->st, philo->id);
	sem_post(philo->gdata->dead);
	ft_exit(philo, 1);
	return (0);
}

size_t	readlm(t_philo *philo)
{
	size_t	d;

	sem_wait(philo->gdata->lm);
	d = philo->lastmeal;
	sem_post(philo->gdata->lm);
	return (d);
}

void	setlm(t_philo *philo)
{
	sem_wait(philo->gdata->lm);
	philo->lastmeal = getime() - philo->st;
	sem_post(philo->gdata->lm);
}
