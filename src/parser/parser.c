/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:25:59 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/05 23:15:11 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parser(t_list *cmds)
{
	t_list	*command;

	if (!check_parse_error(cmds))
		return (0);
	command = cmds;
	while (command)
	{
		collect_files_and_delimiters((t_command *)command->content);
		command = command->next;
	}
	return (1);
}
