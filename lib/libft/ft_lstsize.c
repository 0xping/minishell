/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:52:27 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/03 21:57:51 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	while (lst && lst->prev)
		lst = lst->prev;
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
