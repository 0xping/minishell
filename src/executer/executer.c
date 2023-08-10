/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:52:21 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/10 02:55:30 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

int	open_redirection_and_heredocs(t_list *cmd_list)
{
	check_16_heredocs(cmd_list);
	set_heredocs(cmd_list);
	if (g_vars.heredoc_sig)
	{
		g_vars.heredoc_sig = 0;
		g_vars.exit_status = 1;
		return (1);
	}
	set_redirections(cmd_list);
	return (0);
}

void	executer(t_list *cmd_list)
{
	if (open_redirection_and_heredocs(cmd_list))
		return ;
}
