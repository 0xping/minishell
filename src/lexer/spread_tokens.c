/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spread_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:08:52 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/03 19:50:17 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	push_char_to_str(char **str, char c);
static void	ft_norm(char **p_result, char **p_str);

char	*spread_tokens(char *str)
{
	char	*tmp;
	char	*result;
	char	*s;

	result = ft_strdup("");
	s = str;
	while (*s)
	{
		if ((*s == '<' || *s == '>') && !is_char_quoted(str, s))
		{
			tmp = result;
			ft_norm(&result, &s);
			ft_free(tmp);
		}
		else
			push_char_to_str(&result, *s);
		s++;
	}
	return (result);
}

static void	push_char_to_str(char **str, char c)
{
	char	*c_as_str;
	char	*tmp;

	c_as_str = char_to_str(c);
	tmp = *str;
	*str = ft_strjoin(*str, c_as_str);
	ft_free(tmp);
	ft_free(c_as_str);
}

static void	ft_norm(char **p_result, char **p_str)
{
	char	*result;
	char	*str;

	result = *p_result;
	str = *p_str;
	if (*str == *(str + 1))
	{
		(*str == '<') && (result = ft_strjoin(result, " << "));
		(*str == '>') && (result = ft_strjoin(result, " >> "));
		str++;
	}
	else
	{
		(*str == '<') && (result = ft_strjoin(result, " < "));
		(*str == '>') && (result = ft_strjoin(result, " > "));
	}
	*p_result = result;
	*p_str = str;
}
