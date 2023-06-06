/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:03:00 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/10/15 14:00:43 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	int		j;

	if (!s1 || !s2)
		return (0);
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (result)
	{
		i = 0;
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			result[i] = s2[j];
			j++;
			i++;
		}
	}
	return (result);
}
