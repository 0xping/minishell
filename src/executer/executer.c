/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:52:21 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/17 16:24:36 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

int	exec_builtins(char **cmd)
{
	if (cmd == 0)
		return (0);
	g_vars.exit_status = 0;
	if (!ft_strcmp(*cmd, "cd"))
		ft_cd(cmd);
	if (!ft_strcmp(*cmd, "echo"))
		ft_echo(cmd + 1);
	else if (!ft_strcmp(*cmd, "env"))
		ft_env();
	else if (!ft_strcmp(*cmd, "exit"))
		ft_exit(cmd);
	else if (!ft_strcmp(*cmd, "export"))
		ft_export(cmd);
	else if (!ft_strcmp(*cmd, "pwd"))
		ft_pwd();
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
		g_vars.exit_status = 1;
		return (1);
	}
	set_redirections(cmd_list);
	return (0);
}

int	*dup_fds(int fd1, int fd2)
{
	int	*new_fds;

	new_fds = malloc(2 * sizeof(int));
	new_fds[0] = dup(fd1);
	new_fds[1] = dup(fd2);
	return (new_fds);
}

void	executer(t_list *cmd_list)
{
	t_command	*cmd;
	t_list		*cmd_i;
	int			*new_fds;

	if (open_redirection_and_heredocs(cmd_list))
		return ;
	new_fds = dup_fds(0, 1);
	cmd_i = cmd_list;
	while (cmd_i)
	{
		cmd = (t_command *)cmd_i->content;
		dup2(cmd->fd[0], 0);
		dup2(cmd->fd[1], 1);
		if (!cmd->file_error)
		{
			// fork for a child
			if (exec_builtins(cmd->command))
			{
				// exec none builtins
			}
			// child ends here
		}
		if (cmd->fd[0]) close(cmd->fd[0]);
		(cmd->fd[1] != 1) && (close(cmd->fd[1]), 0);
		cmd_i = cmd_i->next;
	}
	dup2(new_fds[0], 0);
	dup2(new_fds[1], 1);
	ft_free((void**)&new_fds);
}
