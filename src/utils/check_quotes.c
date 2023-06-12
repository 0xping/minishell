/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:54:05 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/02 23:04:43 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_quotes(char *str)
{
	bool double_quote_open = false;
	bool single_quote_open = false;

	int i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			double_quote_open = !double_quote_open;
		else if (str[i] == '\'')
			single_quote_open = !single_quote_open;
		i++;
	}

	if (double_quote_open || single_quote_open)
	{
		printf("error");
	}
}