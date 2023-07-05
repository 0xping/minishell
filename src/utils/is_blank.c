/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:27:35 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/03 19:50:17 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_blank(char *str)
{
	char	*trimmed_str;

	trimmed_str = ft_strtrim(str, " \n\v\f\r\t");
	if (*trimmed_str)
	{
		ft_free(trimmed_str);
		return (0);
	}
	ft_free(trimmed_str);
	return (1);
}