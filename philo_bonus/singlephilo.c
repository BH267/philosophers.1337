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

void	sroutine(void)
{
	size_t	start;

	start = getime();
	printf("%lu %d take a fork\n", getime() - start, 1);
	printf("%lu %d died\n", getime() - start, 1);
}

void	singlephilo(void)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		sroutine();
		exit(0);
	}
	waitpid(pid, NULL, 0);
}
