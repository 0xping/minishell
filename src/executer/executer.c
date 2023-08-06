/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:52:21 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/05 20:21:00 by xshel            ###   ########.fr       */
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

void	ft_free1(char **s)
{
	int	j;

	j = 0;
	while (s[j])
		free(s[j++]);
	free(s);
}

void	child(cmd)
{
	int fd[2];

	if (pipe(fd) == -1)
		return ;
	if (!fork())
	{
		close(fd[0]);
		close(fd[1]);
		execve(get_path(cmd->command[0], my_env), cmd->command, my_env);
		exit(1);
	}
	ft_free1(cmd->command);
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
}

//cmd {*fd, **command}

void	exc_cmd(t_command *cmd)
{
	dup2(cmd->fd[0], 0);
	close(cmd->fd[0]);
	dup2(cmd->fd[1], 1);
	close(cmd->fd[1]);
	child(cmd);
	while (wait(NULL) != -1)
		;
	return ;
}
