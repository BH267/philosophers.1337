/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:19:37 by ybouanan          #+#    #+#             */
/*   Updated: 2025/03/05 08:53:08 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hb_malloc.h"

static struct s_hgc	**get_box(void)
{
	static struct s_hgc	*head;

	return (&head);
}

void	hb_free(void)
{
	struct s_hgc	*current;
	struct s_hgc	*temp;

	current = *get_box();
	while (current)
	{
		free(current->p);
		temp = current;
		current = current->next;
		free(temp);
	}
	*get_box() = NULL;
}

static void	add_to_box(void *addr)
{
	struct s_hgc	*mem_node;

	mem_node = malloc(sizeof(struct s_hgc));
	if (!mem_node)
		return (hb_free(), exit(1));
	mem_node->p = addr;
	mem_node->next = *get_box();
	*get_box() = mem_node;
}

void	*hb_malloc(size_t bytes)
{
	void	*p;

	p = malloc(bytes);
	if (!p)
		return (hb_free(), exit(1), NULL);
	add_to_box(p);
	return (p);
}
