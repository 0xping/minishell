/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/05 15:45:05 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*expander(char *word)
{
	int		i;
	char	*result;

	i = 0;
	result = ft_strdup("");
	while (word[i])
	{
		i++;
	}
	return (result);
}
