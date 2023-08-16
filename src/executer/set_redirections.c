/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:32:30 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/16 16:53:13 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

static int	get_oflag(red_type type)
{
	int	oflag;

	oflag = O_WRONLY | O_CREAT;
	if (type == RED_OUT)
		oflag |= O_TRUNC;
	if(type == RED_APPEND)
		oflag |= O_APPEND;
	if (type == RED_IN || type == RED_HEREDOC)
		oflag = O_RDONLY;
	return (oflag);
}

static int	open_file(t_file *file, int **fd)
{
	int		file_fd;
	char	*err_prompt;

	if (!ft_strcmp(file->name, "/dev/stdin"))
		file_fd = 0;
	else if (!ft_strcmp(file->name, "/dev/stdout"))
		file_fd = 1;
	else if (!ft_strcmp(file->name, "/dev/stderr"))
		file_fd = 2;
	else
		file_fd = open(file->name, get_oflag(file->type), 0644);
	if (file_fd == -1)
	{
		err_prompt = ft_strjoin("minishell: ", file->name);
		perror(err_prompt);
		ft_free((void **)&err_prompt);
		g_vars.exit_status = 1;
		return (1);
	}
	if (file->type == RED_IN || file->type == RED_HEREDOC)
	{
		((*fd)[0] != 0 && (*fd)[0] != 1 && (*fd)[0] != 2) && (close((*fd)[0]),0);
		(*fd)[0] = file_fd;
	}
	else if (file->type == RED_OUT || file->type == RED_APPEND)
	{
		((*fd)[1] != 0 && (*fd)[1] != 1 && (*fd)[1] != 2) && (close((*fd)[1]),0);
		(*fd)[1] = file_fd;
	}
	return (0);
}

void	set_redirections(t_list *cmd_list)
{
	t_command	*cmd;
	t_file		*file;
	t_list		*i_list;
	t_list		*j_list;

	i_list = cmd_list;
	while (i_list)
	{
		cmd = (t_command *)i_list->content;
		cmd->fd[0] = 0;
		cmd->fd[1] = 1;
		j_list = cmd->files;
		while (j_list)
		{
			file = (t_file *)j_list->content;
			if(!cmd->file_error)
				cmd->file_error = open_file(file, &cmd->fd);
			if (cmd->file_error)
				break ;
			j_list = j_list->next;
		}
		i_list = i_list->next;
	}
}
