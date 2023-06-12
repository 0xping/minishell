/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:57:45 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/10 17:22:20 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
			free(tmp);
		}
		tmp = result;
		result = ft_strjoin(result, arr[i]);
		free(tmp);
		i++;
	}
	return (result);
}
