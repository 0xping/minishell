/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_safe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:19:34 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/06 11:29:08 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	count_chunks(char *cmd, char *dels, bool handle_empty_str)
{
	size_t	i;
	size_t	result;
	bool	cond;

	i = 0;
	result = 0;
	while (cmd[i])
	{
		if (handle_empty_str && !is_char_quoted(cmd, &cmd[i]))
			cond = ft_strchr(dels, cmd[i]);
		else
			cond = (i == 0 && !ft_strchr(dels, cmd[i])) || (ft_strchr(dels,
						cmd[i]) && !ft_strchr(dels, cmd[i + 1]) && cmd[i + 1]
					&& !is_char_quoted(cmd, &cmd[i]));
		if (cond)
			result++;
		i++;
	}
	if (handle_empty_str)
		return (result + 1);
	return (result);
}

static void	fill_arr_handel_empty(size_t words, char *s, char *dels,
		char ***result)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < words)
	{
		if (i == 0 && ft_strchr(dels, s[0]))
			(*result)[i] = ft_strdup("");
		else
		{
			if (s[start] && ft_strchr(dels, s[start]) && !is_char_quoted(s,
					&s[start]))
				start++;
			end = start;
			while (s[end] && (!ft_strchr(dels, s[end]) || is_char_quoted(s,
						&s[end])))
				end++;
			(*result)[i] = ft_substr(s, start, end - start);
			start = end;
		}
		i++;
	}
}

static void	fill_arr(size_t words, char *s, char *dels, char ***result)
{
	size_t	i;
	size_t	start;
	size_t	end;

	end = 0;
	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] && ft_strchr(dels, s[start]) && !is_char_quoted(s,
				&s[start]))
			start++;
		end = start;
		while (s[end] && (!ft_strchr(dels, s[end]) || is_char_quoted(s,
					&s[end])))
			end++;
		(*result)[i] = ft_substr(s, start, end - start);
		start = end;
		i++;
	}
}

char	**split_quote_safe(char *cmd, char *dels, bool handle_empty_str)
{
	char	**result;
	size_t	slices;

	if (!cmd)
		return (0);
	slices = count_chunks(cmd, dels, handle_empty_str);
	printf("-->%zu\n", slices);
	result = ft_calloc(slices + 1, sizeof(char *));
	if (result)
	{
		if (handle_empty_str)
			fill_arr_handel_empty(slices, cmd, dels, &result);
		else
			fill_arr(slices, cmd, dels, &result);
	}
	return (result);
}
