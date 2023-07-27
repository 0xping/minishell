/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:52:21 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/10 18:01:20 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	executer(t_list *cmd_list)
{
	set_heredocs(cmd_list);
	if (g_vars.heredoc_sig)
	{
		g_vars.heredoc_sig = 0;
		return ;
	}
	set_redirections(cmd_list);
}