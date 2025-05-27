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

# define BLUE "\033[0;36m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define DEFULT "\033[0m"

# define DEAD 0
# define EAT 1
# define SLEEP 2
# define THINK 3

typedef struct s_argument
{
	long long	np;
	long long	ttd;
	long long	tte;
	long long	tts;
	long long	nte;
}	t_args;

typedef struct s_philo
{
	pthread_t			*philo;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		rfork;
	t_args				*gdata;
	int					id;
	size_t				lastmeal;
	ssize_t				nmeals;
	size_t				st;
	pthread_mutex_t		*isdead;
	pthread_mutex_t		lm;
	struct s_philo		*next;
}	t_philo;

int		hb_isdigit(int n);
void	*monitor(void *philo);
size_t	getime(void);
void	*routine(void *philo);
void	hb_usleep(size_t sleep, t_philo *philo);
t_philo	*makephilos(t_args *data);
t_args	*setargs(char **av);
ssize_t	hb_atou(const char *nbr);
t_philo	*lastphilo(t_philo *lst);
void	philoadd_back(t_philo **lst, t_philo *newph);
t_philo	*newphilo(pthread_t *phl, pthread_mutex_t fork, t_args *gdata);
int		setdead(t_philo *philo, int d);
int		readead(t_philo *philo);
size_t	setlm(t_philo *philo);
size_t	readlm(t_philo *philo);
void	singlephilo(void);
int		*dead(void);
void	takefork(t_philo *philo);
void	putfork(t_philo *philo);
void	print(int state, t_philo *philo);
char	*hb_itoa(size_t d);
size_t	hb_strlen(const char *str);
char	*hb_strdup(const char *str);

#endif
