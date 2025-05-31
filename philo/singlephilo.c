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

void	*sroutine(void *dataa)
{
	size_t			start;
	t_args			*data;
	pthread_mutex_t	fork;

	data = (t_args *)dataa;
	start = getime();
	pthread_mutex_init(&fork, NULL);
	pthread_mutex_lock(&fork);
	printf("%lu %d take a fork\n", getime() - start, 1);
	usleep(data->ttd * 1000);
	pthread_mutex_unlock(&fork);
	printf("%lu %d died\n", getime() - start, 1);
	return (NULL);
}

void	singlephilo(t_args *data)
{
	pthread_t	th;

	pthread_create(&th, NULL, sroutine, data);
	pthread_join(th, NULL);
}
