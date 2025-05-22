/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:45:18 by habenydi          #+#    #+#             */
/*   Updated: 2025/04/05 15:47:09 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*setargs(char **av)
{
	t_args	*args;

	args = (t_args*)malloc(sizeof(t_args));
	args->nte = -1;
	args->np = hb_atou(av[1]);
	args->ttd = hb_atou(av[2]);
	args->tte = hb_atou(av[3]);
	args->tts = hb_atou(av[4]);
	if (av[5])
		args->nte = hb_atou(av[5]);
	if (args->np > 200 || args->np <= 0 || args->ttd < 60
		|| args->tte < 60 || args->tts < 60 || args->nte < -1)
		return (NULL);
	return (args);
}

int	main(int ac, char **av)
{
	t_args	*args;

	if (ac < 5 || 6 < ac)
		return (printf("   usage : <./philo np ttd tte tts nte(op)>\n"), 1);
	args = setargs(av);
	if (!args)
		return (printf("invalid argument\n"),1);
	makephilos(args);
}
