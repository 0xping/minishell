/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_char_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:41:53 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/06 19:04:17 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	push_char_to_str(char **str, char c)
{
	char	*c_as_str;
	char	*tmp;

	c_as_str = char_to_str(c);
	tmp = *str;
	*str = ft_strjoin(*str, c_as_str);
	ft_free((void **)&tmp);
	ft_free((void **)&c_as_str);
}
