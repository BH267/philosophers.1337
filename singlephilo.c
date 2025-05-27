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

void	*sroutine(void *null)
{
	size_t	start;

	start = getime();
	(void)null;
	printf("%lu %d take a fork\n", getime() - start, 1);
	printf("%lu %d died\n", getime() - start, 1);
	return (NULL);
}

void	singlephilo(void)
{
	pthread_t	th;

	pthread_create(&th, NULL, sroutine, NULL);
	pthread_join(th, NULL);
}
