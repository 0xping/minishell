/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:27:35 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/12 16:05:23 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_blank(char *str)
{
	char	*trimmed_str;

	trimmed_str = ft_strtrim(str, " \n\v\f\r\t");
	if (*trimmed_str)
	{
		free(trimmed_str);
		return (0);
	}
	free(trimmed_str);
	return (1);
}
