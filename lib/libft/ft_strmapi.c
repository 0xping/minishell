/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:34:27 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/10/24 22:47:19 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	i;
	char	*result;

	i = 0;
	if (!s || !f)
		return (0);
	s_len = ft_strlen(s);
	result = ft_calloc(s_len + 1, 1);
	if (result)
	{
		while (i < s_len)
		{
			result[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (result);
}
