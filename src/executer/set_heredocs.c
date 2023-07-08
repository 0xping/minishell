/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heredocs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:38:51 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/08 12:51:37 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_heredoc_filename(char *del, int index)
{
	char	*index_as_str;
	char	*ttyslot_as_str;
	char	*filename;

	index_as_str = char_to_str(index + '0');
	ttyslot_as_str = char_to_str(ttyslot() + '0');
	filename = join_strings((char *[]){"/tmp/", del, ttyslot_as_str,
			index_as_str}, 4, "");
	ft_free(index_as_str);
	ft_free(ttyslot_as_str);
	return (filename);
}

static void	create_heredoc_file(t_file *file, int index)
{
	char	*file_name;
	int		fd;
	char	*line;

	file_name = get_heredoc_filename(file->name, index);
	fd = open(file_name, O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0644);
	line = 0;
	while (!line || ft_strcmp(line, file->name))
	{
		line = readline(">");
		if (ft_strcmp(line, file->name))
			ft_putendl_fd(line, fd);
		ft_free(line);
	}
	close(fd);
	file->name = file_name;
}

void	set_heredocs(t_list *cmd_list)
{
	t_command	*cmd;
	t_file		*file;
	t_list		*i_list;
	t_list		*j_list;
	int			i;

	i = 0;
	i_list = cmd_list;
	while (i_list)
	{
		cmd = (t_command *)i_list->content;
		cmd->fd = ft_calloc(2, sizeof(int));
		j_list = cmd->files;
		while (j_list)
		{
			file = (t_file *)j_list->content;
			if (file->type == RED_HEREDOC)
				create_heredoc_file(file, i++);
			j_list = j_list->next;
		}
		i_list = i_list->next;
	}
}
