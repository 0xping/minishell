/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:52:00 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/18 11:41:28 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

char	*get_quote_content(char *s)
{
	char	quote;

	quote = *s;
	if (s[1] == 0)
		return (ft_strdup(""));
	return (ft_substr(s + 1, 0, ft_strchr(s + 1, quote) - s - 1));
}
