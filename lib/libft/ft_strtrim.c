/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 01:41:12 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/10/15 13:49:49 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_includes(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_first_char(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_includes(set, s1[i]))
		i++;
	return (i);
}

static size_t	get_last_char(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_includes(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	start = get_first_char(s1, set);
	end = get_last_char(s1, set) + 1;
	if (end > start)
		result = ft_substr(s1, start, end - start);
	else
		result = ft_strdup("");
	return (result);
}

// int	main(int argc, char const *argv[])
// {
// 	argc++;
// 	printf("%p", ft_strtrim(argv[1], argv[2]));
// 	return (0);
// }
