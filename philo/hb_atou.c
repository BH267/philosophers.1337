/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:05:45 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/07 09:44:05 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

ssize_t	hb_atou(const char *nbr)
{
	ssize_t	n;

	n = 0;
	if (nbr == NULL)
		return (0);
	while (!hb_isdigit(*nbr) && *nbr != '-' && *nbr != '+')
	{
		if ((9 <= *nbr && *nbr <= 13) || *nbr == 32)
			nbr++;
		else
			return (-1);
	}
	if (*nbr == '-' || *nbr == '+')
		if (*(nbr++) == '-')
			return (-1);
	while (hb_isdigit(*nbr))
		n = n * 10 + (*(nbr++) - '0');
	if (!hb_isdigit(*nbr) && *nbr != 0)
		return (-1);
	return (n);
}
