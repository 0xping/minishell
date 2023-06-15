/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_splitter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:34:27 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/15 16:27:59 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	count_chunks(char *cmd)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (cmd[i])
	{
		if (cmd[i] == '|' && !is_char_quoted(cmd, &cmd[i]))
			result++;
		i++;
	}
	return (result + 1);
}

static void	fill_arr_with_chunks(size_t words, char *s, char ***result)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < words)
	{
		if (i == 0 && s[0] == '|')
			(*result)[i] = ft_strdup("");
		else
		{
			if (s[start] && s[start] == '|' && !is_char_quoted(s, &s[start]))
				start++;
			end = start;
			while (s[end] && (s[end] != '|' || is_char_quoted(s, &s[end])))
				end++;
			(*result)[i] = ft_substr(s, start, end - start);
			start = end;
		}
		i++;
	}
}

char	**pipe_splitter(char *cmd)
{
	char	**result;

	if (!cmd)
		return (0);
	result = ft_calloc(count_chunks(cmd) + 1, sizeof(char *));
	if (result)
	{
		fill_arr_with_chunks(count_chunks(cmd), cmd, &result);
	}
	return (result);
}
