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
	n = (t_philo *)hb_malloc(sizeof(t_philo));
	if (!n)
		return (NULL);
	n->nmeals = 0;
	n->id = id;
	n->st = getime();
	n->gdata = gdata;
	n->lastmeal = 0;
	n->next = NULL;
	return (n);
}

void	hb_clearphilo(t_philo **lst)
{
	if (!lst)
		return ;
	free((*lst)->gdata);
	(*lst)->gdata = NULL;
	free(*lst);
	lst = NULL;
}

void	hb_lstclear(t_philo **lst)
{
	t_philo	*n;
	int		i;
	int		np;

	if (!lst)
		return ;
	np = (*lst)->gdata->np;
	i = 0;
	while (i++ < np)
	{
		n = (*lst)->next;
		free(*lst);
		*lst = n;
	}
	lst = NULL;
}
