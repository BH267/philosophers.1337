/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:43:23 by habenydi          #+#    #+#             */
/*   Updated: 2025/04/05 15:43:30 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
#include <bits/pthreadtypes.h>

typedef struct s_argument {
	ssize_t	np;
	ssize_t	ttd;
	ssize_t	tte;
	ssize_t	tts;
	ssize_t	nte;
} t_args;

typedef struct s_philo {
	pthread_t		*philo;
	pthread_mutex_t		lfork;
	pthread_mutex_t		rfork;
	int				id;
	struct s_philo		*next;
}	t_philo;

int		hb_isdigit(int n);
t_philo	*makephilos(int np);
t_args	*setargs(char **av);
ssize_t	hb_atou(const char *nbr);
t_philo	*lastphilo(t_philo *lst);
void	philoadd_back(t_philo **lst, t_philo *newph);
t_philo	*newphilo(pthread_t *phl);


#endif
