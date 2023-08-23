/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:50:09 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/23 15:38:06 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

int	exec_builtins(char **cmd, int wr)
{
	if (cmd == 0)
		return (0);
	g_vars.exit_status = 0;
	if (!ft_strcmp(*cmd, "cd"))
		ft_cd(cmd);
	if (!ft_strcmp(*cmd, "echo"))
		ft_echo(cmd + 1, wr);
	else if (!ft_strcmp(*cmd, "env"))
		ft_env(wr);
	else if (!ft_strcmp(*cmd, "exit"))
		ft_exit(cmd);
	else if (!ft_strcmp(*cmd, "export"))
		ft_export(cmd, wr);
	else if (!ft_strcmp(*cmd, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(*cmd, "unset"))
		ft_unset(cmd);
	else
		return (0);
	return (1);
}

int	open_redirection_and_heredocs(t_list *cmd_list)
{
	check_16_heredocs(cmd_list);
	set_heredocs(cmd_list);
	if (g_vars.heredoc_sig)
	{
		g_vars.heredoc_sig = 0;
		return (1);
	}
	set_redirections(cmd_list);
	return (0);
}
