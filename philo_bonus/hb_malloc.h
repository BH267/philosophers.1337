/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:13:51 by ybouanan          #+#    #+#             */
/*   Updated: 2025/03/03 17:18:47 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HB_MALLOC_H
# define HB_MALLOC_H

# include <stdlib.h>

typedef struct s_hgc
{
	void			*p;
	struct s_hgc	*next;
}				t_hgc;

void			*hb_malloc(size_t bytes);
void			hb_free(void);

#endif
