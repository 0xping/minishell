/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:03:00 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/10 17:21:23 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s1 && !s2)
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
			result[i++] = s2[j++];
	}
	return (result);
}
