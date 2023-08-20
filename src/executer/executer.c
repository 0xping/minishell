/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:52:21 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/20 19:46:09 by aait-lfd         ###   ########.fr       */
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
		g_vars.exit_status = 1;
		return (1);
	}
	set_redirections(cmd_list);
	return (0);
}

// int	*dup_fds(int fd1, int fd2)
// {
// 	int	*new_fds;

// 	new_fds = malloc(2 * sizeof(int));
// 	new_fds[0] = dup(fd1);
// 	new_fds[1] = dup(fd2);
// 	return (new_fds);
// }

void	child(int rd, int wr, t_command *cmd, int i, int prd, int pwr)
{
	g_vars.pid[i] = fork();
	if (g_vars.pid[i] == 0)
	{
		if (is_builtins(cmd->command))
		{
			exec_builtins(cmd->command, wr);
			exit(0);
		}
		dup2(rd, 0);
		if (rd != 0)
			close(rd);
		dup2(wr, 1);
		if (wr != 1)
			close(wr);
		close(prd);
		close(pwr);
		if (!is_builtins(cmd->command))
		{
			execve(get_path(cmd->command), cmd->command, (char **)g_vars.envp);
			perror("execve");
			exit(1);
		}
	}
}

void	executer(t_list *cmd_list)
{
	t_list		*current;
	int			rd;
	int			wr;
	int			i;
	t_command	*cmd;

	current = cmd_list;
	wr = 1;
	int pipe_fd[5][2]; // you should allocate this array dynamically
	i = 0;
	if (open_redirection_and_heredocs(cmd_list))
		return ;
	g_vars.pid = malloc(sizeof(pid_t) * ft_lstsize(cmd_list));
	while (current)
	{
		rd = 0;
		wr = 1;
		cmd = (t_command *)current->content;
		if(cmd->command)
		{
			if (is_builtins(cmd->command) && ft_lstsize(cmd_list) == 1)
			{
				if (cmd->fd[0] != 0 || cmd->fd[1] != 1)
				{
					rd = cmd->fd[0];
					wr = cmd->fd[1];
				}
				exec_builtins(cmd->command, wr);
			}
			else
			{
				if (i > 0)
					rd = pipe_fd[i - 1][0];
				if (current->next)
				{
					(pipe(pipe_fd[i]) == -1) && (perror("pipe"), 1);
					wr = pipe_fd[i][1];
				}
				if (cmd->fd[0] != 0)
				{
					(rd) && (close(rd), 1);
					rd = cmd->fd[0];
				}
				if (cmd->fd[1] != 1)
				{
					(wr != 1) && (close(wr), 1);
					wr = cmd->fd[1];
				}
				child(rd, wr, cmd, i, pipe_fd[i][0], pipe_fd[i][1]);
				wr != 1 && (close(wr), 1);
				rd && (close(rd), 1);
			}
			i++;
		}
		current = current->next;
	}
	i = 0;
	while (i < ft_lstsize(cmd_list))
		waitpid(g_vars.pid[i++], &g_vars.exit_status, 0);
	ft_free((void **)&g_vars.pid);
}
