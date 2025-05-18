/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:00 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/16 15:39:08 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	getime(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (printf("gettimeofday : %s\n", strerror(errno)), 1);
	return (tv.tv_sec * 100000 + tv.tv_usec / 10);
}

void	hb_usleep(size_t sleep)
{
	size_t	ctime;

	ctime = getime();
	if (ctime == 1)
		return ;
	while ((getime() - ctime) < sleep)
		usleep(1);
}
