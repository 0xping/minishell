/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:50:58 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/10/25 21:15:27 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_c(char const *s, char c)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != c && s[i + 1]))
			result++;
		i++;
	}
	return (result);
}

static int	ft_free(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		result[i] = 0;
		i--;
	}
	free(result);
	return (0);
}

static int	ft_fill(size_t words, const char *s, char c, char ***result)
{
	size_t	i;
	size_t	start;
	size_t	end;

	end = 0;
	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] == c && s[start])
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		(*result)[i++] = ft_substr(s, start, end - start);
		if ((*result)[i - 1] == 0)
		{
			ft_free(*result, i - 1);
			return (0);
		}
		start = end;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = ft_calloc(count_c(s, c) + 1, sizeof(char *));
	if (result)
	{
		if (ft_fill(count_c(s, c), s, c, &result) == 0)
			return (0);
	}
	return (result);
}
