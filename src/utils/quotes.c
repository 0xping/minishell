/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:54:05 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/15 13:57:30 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Checks if there are any unclosed quotes in the given string.
 *
 * @param str The input string to be checked.
 *

	* @return The type of unclosed quote found (single or double) if there is an unclosed quote,
 *         otherwise 0.
 */
char	check_quotes(char *str)
{
	bool	double_quote_status;
	bool	single_quote_status;

	double_quote_status = false;
	single_quote_status = false;
	while (*str)
	{
		if (*str == '"')
			double_quote_status = !double_quote_status;
		else if (*str == '\'')
			single_quote_status = !single_quote_status;
		str++;
	}
	if (double_quote_status)
		return ('"');
	if (single_quote_status)
		return ('\'');
	return (0);
}

/**
 * Determines whether a specific character in a string is quoted.
 *

	* This function iterates through the provided string to check if the character at the
 * given position is enclosed within single quotes (' ') or double quotes (" ").
 *
 * @param str A pointer to a null-terminated string.
 * @param pos A pointer to the position in the string to check.
 *

	* @return 1 if the character at the given position is quoted with single or double quotes,
	*         0 if the character is not quoted or there are no active quotes in the string.
 */
int	is_char_quoted(char *str, char *pos)
{
	bool	double_quote_status;
	bool	single_quote_status;

	double_quote_status = false;
	single_quote_status = false;
	while (str)
	{
		if (str == pos)
		{
			if (*str == '"' || *str == '\'')
				return (1);
			return (double_quote_status || single_quote_status);
		}
		if (*str == '"')
			double_quote_status = !double_quote_status;
		else if (*str == '\'')
			single_quote_status = !single_quote_status;
		str++;
	}
	return (0);
}
