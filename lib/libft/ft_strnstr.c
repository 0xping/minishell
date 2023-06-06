/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:18:59 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/10/23 20:20:01 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	if (!haystack && !len)
		return (0);
	if (!needle[0])
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0 && (needle_len
				+ i <= len))
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
