/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makephilos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:29:41 by habenydi          #+#    #+#             */
/*   Updated: 2025/06/19 19:19:04 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initlocks(t_args **arg)
{
	sem_unlink("fork");
	sem_unlink("lm");
	sem_unlink("dead");
	sem_unlink("deadlock");
	(*arg)->forks = sem_open("fork", O_CREAT, 0644, (*arg)->np);
	(*arg)->lm = sem_open("lm", O_CREAT, 0644, 1);
	(*arg)->mat = sem_open("dead", O_CREAT, 0644, 1);
	(*arg)->dead = sem_open("deadlock", O_CREAT, 0644, 1);
}

void	destroylocks(t_args *args)
{
	if (args->forks)
		sem_close(args->forks);
	if (args->dead)
		sem_close(args->dead);
	if (args->lm)
		sem_close(args->lm);
	if (args->mat)
		sem_close(args->mat);
	sem_unlink("fork");
	sem_unlink("lm");
	sem_unlink("dead");
	sem_unlink("deadlock");
}

void	philogo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i++ < philo->gdata->np)
	{
		philo->philo = fork();
		if (philo->philo == 0)
		{
			routine(philo);
			ft_exit(philo, 0);
		}
		philo = philo->next;
	}
	i = 0;
	while (i++ < philo->gdata->np)
	{
		waitpid(philo->philo, NULL, 0);
		philo = philo->next;
	}
}

t_philo	*makephilos(t_args *args)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = NULL;
	while (i++ < args->np)
		philoadd_back(&philos, newphilo(args));
	lastphilo(philos)->next = philos;
	philogo(philos);
	destroylocks(philos->gdata);
	return (NULL);
}
