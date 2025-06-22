/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singlephilo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:58:33 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/24 15:58:57 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sroutine(t_args *args)
{
	size_t	start;

	if (args->nte == 0)
		return ;
	sem_unlink("fork");
	start = getime();
	sem_wait(args->forks);
	printf("%lu %d take a fork\n", getime() - start, 1);
	hb_usleep(args->ttd);
	printf("%lu %d died\n", getime() - start, 1);
	sem_post(args->forks);
	destroylocks(args);
}

void	singlephilo(t_args *args)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		sroutine(args);
		free(args);
		args = NULL;
		exit(0);
	}
	else if (pid < 0)
	{
		write(2, "fork fails\n", 11);
		free(args);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	destroylocks(args);
}
