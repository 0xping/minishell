/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:04:26 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/17 12:38:27 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

bool	is_char_special(char c)
{
	char	*special_characters;

	special_characters = "$!#%*(){}[]/\"'|\\;:,<>?&=+-. \t\n";
	return (ft_strchr(special_characters, c));
}
