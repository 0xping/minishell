/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:10:00 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/06 19:04:17 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	push_str(char ***ptr_arr, char *str)
{
	int		size;
	char	**arr;
	char	**new_arr;
	int		i;

	size = 0;
	arr = *ptr_arr;
	while (arr && arr[size])
		size++;
	new_arr = ft_calloc(size + 2, sizeof(char *));
	i = 0;
	while (arr && arr[i])
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = str;
	ft_free((void **)&*ptr_arr);
	*ptr_arr = new_arr;
	return (1);
}
