/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:50:12 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/23 11:15:04 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	handle_single_builtin(t_executer *executer)
{
	if (executer->cmd->fd[0] != 0 || executer->cmd->fd[1] != 1)
	{
		executer->rd = executer->cmd->fd[0];
		executer->wr = executer->cmd->fd[1];
	}
	exec_builtins(executer->cmd->command, executer->wr);
}

void	setup_pipe_and_fds(t_executer *executer, t_list *current)
{
	if (executer->i > 0)
		executer->rd = executer->pipe_fd[executer->i - 1][0];
	if (current->next)
	{
		executer->pipe_fd[executer->i] = malloc(sizeof(int) * 2);
		if (pipe(executer->pipe_fd[executer->i]) == -1)
			perror("pipe");
		executer->wr = executer->pipe_fd[executer->i][1];
	}
}

void	handle_fd(t_executer *executer)
{
	if (executer->cmd->fd[0] != 0)
	{
		if (executer->rd)
			close(executer->rd);
		executer->rd = executer->cmd->fd[0];
	}
	if (executer->cmd->fd[1] != 1)
	{
		if (executer->wr != 1)
			close(executer->wr);
		executer->wr = executer->cmd->fd[1];
	}
}

void	cleanup_pipe_and_fds(t_executer *executer, t_list *current)
{
	if (!current->next)
		executer->pipe_fd[executer->i] = NULL;
	child(executer);
	if (executer->wr != 1)
		close(executer->wr);
	if (executer->rd)
		close(executer->rd);
}
