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
# include <string.h>
# include <errno.h>
# include <time.h>
# include <sys/time.h>
# include <bits/pthreadtypes.h>

typedef struct s_argument {
	long long	np;
	long long	ttd;
	long long	tte;
	long long	tts;
	long long	nte;
} t_args;

typedef struct s_philo {
	pthread_t		*philo;
	pthread_mutex_t		lfork;
	pthread_mutex_t		rfork;
	t_args			*gdata;
	int				id;
	struct s_philo		*next;
}	t_philo;

int		hb_isdigit(int n);
void	*routine(void *philo);
void	hb_usleep(size_t sleep);
t_philo	*makephilos(t_args *data);
t_args	*setargs(char **av);
ssize_t	hb_atou(const char *nbr);
t_philo	*lastphilo(t_philo *lst);
void	philoadd_back(t_philo **lst, t_philo *newph);
t_philo	*newphilo(pthread_t *phl, t_args *gdata);


#endif
