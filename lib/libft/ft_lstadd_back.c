/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:46:51 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/02 21:33:04 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst)
		return ;
	last_node = ft_lstlast(*lst);
	if (*lst)
	{
		last_node->next = new;
		new->prev = last_node;
	}
	else
	{
		*lst = new;
		new->prev = 0;
	}
}
