/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:57:45 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/06 21:32:22 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

char	*join_strings(char **arr, int size, char *sep)
{
	char	*result;
	char	*tmp;
	int		i;

	result = 0;
	i = 0;
	while (i < size)
	{
		if (sep && result)
		{
			tmp = result;
			result = ft_strjoin(result, sep);
			ft_free((void **)&tmp);
		}
		tmp = result;
		result = ft_strjoin(result, arr[i]);
		ft_free((void **)&tmp);
		i++;
	}
	return (result);
}
