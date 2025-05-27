/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:18:48 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/11 09:33:02 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	hb_lenum(size_t n, int nega)
{
	size_t	l;

	l = 1;
	if (nega)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		l++;
	}
	if (nega)
		return (l + 1);
	return (l);
}

static size_t	hb_nega(size_t n, char *num)
{
	*num = '-';
	n *= -1;
	return (n);
}

char	*hb_itoa(size_t n)
{
	char	*num;
	int		nega;
	int		lenum;

	num = NULL;
	nega = (n < 0);
	lenum = hb_lenum(n, nega);
	num = malloc(lenum + 1);
	if (!num)
		return (NULL);
	if (nega)
		n = hb_nega(n, num);
	num[lenum--] = '\0';
	while (0 <= lenum)
	{
		if (nega && !lenum)
			break ;
		num[lenum--] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}
