/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:54:05 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/30 02:22:08 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	check_quotes(char *str)
{
	bool	double_quote_status;
	bool	single_quote_status;

	double_quote_status = false;
	single_quote_status = false;
	while (*str)
	{
		if (*str == '"' && !single_quote_status)
			double_quote_status = !double_quote_status;
		else if (*str == '\'' && !double_quote_status)
			single_quote_status = !single_quote_status;
		str++;
	}
	if (double_quote_status)
		return ('"');
	if (single_quote_status)
		return ('\'');
	return (0);
}

int	is_char_single_quoted(char *str, char *pos)
{
	bool	single_quote_status;

	single_quote_status = false;
	while (str)
	{
		if (str == pos)
		{
			if (*str == '\'')
				return (1);
			return (single_quote_status);
		}
		else if (*str == '\'')
			single_quote_status = !single_quote_status;
		str++;
	}
	return (0);
}

int	is_char_double_quoted(char *str, char *pos)
{
	bool	double_quote_status;

	double_quote_status = false;
	while (str)
	{
		if (str == pos)
		{
			if (*str == '"')
				return (1);
			return (double_quote_status);
		}
		else if (*str == '"')
			double_quote_status = !double_quote_status;
		str++;
	}
	return (0);
}

int	is_char_quoted(char *str, char *pos)
{
	bool	double_quote_status;
	bool	single_quote_status;

	double_quote_status = is_char_double_quoted(str, pos);
	single_quote_status = is_char_single_quoted(str, pos);
	return (double_quote_status || single_quote_status);
}
