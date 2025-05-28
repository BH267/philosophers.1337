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

t_philo	*newphilo(t_args *gdata)
{
	t_philo		*n;
	static int	id;

	id += 1;
	n = (t_philo *)malloc(sizeof(t_philo));
	if (!n)
		return (NULL);
	n->nmeals = 0;
	n->id = id;
	n->st = getime();
	n->gdata = gdata;
	n->next = NULL;
	return (n);
}

void	hb_clearphilo(t_philo **lst)
{
	t_philo	*n;
	int	i;
	int	np;
	int	pid;

	if (!lst)
		return ;
	pid = 0;
	np = (*lst)->gdata->np;
	free((*lst)->gdata);
	(*lst)->gdata = NULL;
	i = 0;
	while (i < np)
	{
		n = (*lst)->next;
		pid = (*lst)->philo;
		free(*lst);
		kill(pid, SIGINT);
		*lst = n;
		i++;
	}
	lst = NULL;
}
