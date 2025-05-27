/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:11:22 by habenydi          #+#    #+#             */
/*   Updated: 2025/05/12 15:36:50 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*lastphilo(t_philo *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	philoadd_back(t_philo **lst, t_philo *newph)
{
	if (!lst || !newph)
		return ;
	if (*lst)
		lastphilo(*lst)->next = newph;
	else
		*lst = newph;
}

t_philo	*newphilo(pthread_t *phl, pthread_mutex_t fork, t_args *gdata)
{
	t_philo		*n;
	static int	id;

	id += 1;
	n = (t_philo *)malloc(sizeof(t_philo));
	if (!n)
		return (NULL);
	n->philo = phl;
	n->rfork = fork;
	n->nmeals = 0;
	n->id = id;
	n->st = getime();
	n->gdata = gdata;
	n->next = NULL;
	return (n);
}
