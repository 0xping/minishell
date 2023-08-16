/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:08:54 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/16 16:14:03 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

char *remove_quotes(char *s)
{
	int i = 0;
	char *result = ft_strdup("");
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			if (is_char_quoted(s, s + i))
			{
				push_char_to_str(&result, s[i]);
				s[i] *= -1;
			}
		}
		else
			push_char_to_str(&result,s[i]);
		i++;
	}
	return (result);
}
