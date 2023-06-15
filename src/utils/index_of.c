/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:04:52 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/15 14:41:01 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * index_of - Finds the first occurrence of the character c in the string str.
 *
 * @param str: The string to search.
 * @param c: The character to search for.
 *
 * @return The index of the first occurrence of c in str, or
	-1 if c is not found.
 */
int	index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
