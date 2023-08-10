/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:00:14 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/10 03:56:30 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

char	*get_prompt(void)
{
	// if (g_vars.exit_status == 0)
	// 	return (TEXT_REVERSE TEXT_BOLD BG_COLOR_GREEN COLOR_WHITE " minishell:$ " TEXT_RESET " " RESET_ALL);
	// else
	// 	return (TEXT_REVERSE TEXT_BOLD BG_COLOR_RED COLOR_WHITE " minishell:$ " TEXT_RESET " " RESET_ALL);
	if (g_vars.exit_status == 0)
		return (COLOR_GREEN "➜ " RESET_ALL TEXT_BOLD COLOR_YELLOW " minishell " RESET_ALL);
	else
		return (COLOR_RED "➜ " RESET_ALL TEXT_BOLD COLOR_YELLOW " minishell " RESET_ALL);
}
