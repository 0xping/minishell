/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:52:27 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/02 21:28:44 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	while (lst->prev)
		lst = lst->prev;
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
