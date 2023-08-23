/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:52:21 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/23 15:32:15 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	cleanup(int **pipe_fd)
{
	int	j;

	j = 0;
	while (pipe_fd[j])
	{
		free(pipe_fd[j]);
		j++;
	}
	free(pipe_fd);
}

void	child(t_executer *ex)
{
	g_vars.pid[ex->i] = fork();
	if (g_vars.pid[ex->i] == 0)
	{
		if (is_builtins(ex->cmd->command))
		{
			exec_builtins(ex->cmd->command, ex->wr);
			exit(0);
		}
		dup2(ex->rd, 0);
		dup2(ex->wr, 1);
		(ex->rd) && (close(ex->rd), 1);
		(ex->wr != 1) && (close(ex->wr), 1);
		if (ex->pipe_fd[ex->i])
		{
			close(ex->pipe_fd[ex->i][0]);
			close(ex->pipe_fd[ex->i][1]);
		}
		if (!is_builtins(ex->cmd->command))
		{
			execve(get_path(ex->cmd->command), ex->cmd->command,
				(char **)g_vars.envp);
			perror("execve");
			exit(1);
		}
	}
}

void	_exc(t_executer *executer, t_list *current, t_list *cmd_list)
{
	if (is_builtins(executer->cmd->command) && ft_lstsize(cmd_list) == 1)
		handle_single_builtin(executer);
	else
	{
		setup_pipe_and_fds(executer, current);
		handle_fd(executer);
		cleanup_pipe_and_fds(executer, current);
	}
}

void	wait_child(t_list *cmd_list)
{
	int	i;
	int	d;

	i = 0;

	t_list *i_cmd;
	i_cmd = cmd_list;
	while (i_cmd)
	{
		if (g_vars.pid[i])
		{
			waitpid(g_vars.pid[i], &d, 0);
			g_vars.exit_status = WEXITSTATUS(d);
		}
		i++; 	
		i_cmd = i_cmd->next;
	}
}

int	executer(t_list *cmd_list)
{
	t_list		*current;
	t_executer	*executer;

	current = cmd_list;
	if (open_redirection_and_heredocs(cmd_list))
		return (1);
	executer = malloc(sizeof(t_executer));
	g_vars.pid = ft_calloc(sizeof(pid_t) , ft_lstsize(cmd_list));
	executer->pipe_fd = ft_calloc(sizeof(int *), ft_lstsize(cmd_list) + 1);
	executer->i = 0;
	while (current)
	{
		executer->rd = 0;
		executer->wr = 1;
		executer->cmd = (t_command *)current->content;
		if (executer->cmd->command && !executer->cmd->file_error)
		{
			_exc(executer, current, cmd_list);
			++executer->i;
		}
		current = current->next;
	}
	// if (!is_builtins(executer->cmd->command) || ft_lstsize(cmd_list) > 1)
	wait_child(cmd_list);
	cleanup(executer->pipe_fd);
	return (free(executer), ft_free((void **)&g_vars.pid), 0);
}
