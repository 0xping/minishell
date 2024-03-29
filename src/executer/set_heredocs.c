/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heredocs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:38:51 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/28 19:53:20 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

char	*get_heredoc_filename(char *del, int index)
{
	char	*index_as_str;
	char	*filename;

	index_as_str = char_to_str(index + '0');
	filename = join_strings((char *[]){"/tmp/", del, index_as_str,
			ft_strrchr(ttyname(1), '/') + 1}, 4, "");
	ft_free((void **)&index_as_str);
	return (filename);
}

typedef struct s_heredoc_data
{
	char	*file_name;
	int		fd;
	char	*line;
	char	*del;
}			t_heredoc_data;

static void	init_heredoc_dt(t_heredoc_data *dt, t_file *file, int index)
{
	dt->del = remove_quotes(file->name);
	dt->file_name = get_heredoc_filename(dt->del, index);
	dt->fd = open(dt->file_name, O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0644);
	dt->line = 0;
}

static char	*create_heredoc_file(t_file *file, int index)
{
	t_heredoc_data	dt;
	char			*tmp;

	init_heredoc_dt(&dt, file, index);
	while ((!dt.line || ft_strcmp(dt.line, dt.del)) && !g_vars.heredoc_sig)
	{
		ft_free((void **)&dt.line);
		dt.line = readline(">");
		if (dt.line == 0)
			break ;
		if (ft_strcmp(dt.line, dt.del))
		{
			if (!ft_strchr(file->name, '"') && !ft_strchr(file->name, '\''))
			{
				tmp = expander(dt.line, true);
				ft_putendl_fd(tmp, dt.fd);
				ft_free((void **)&tmp);
			}
			else
				ft_putendl_fd(dt.line, dt.fd);
		}
	}
	return (close(dt.fd), ft_free((void **)&dt.line), ft_free((void **)&dt.del),
		ft_free((void **)&file->name), (file->name = dt.file_name));
}

void	set_heredocs(t_list *cmd_list)
{
	t_file	*file;
	t_list	*i_list;
	t_list	*j_list;
	int		i;
	int		new_stdin;

	i = 0;
	new_stdin = dup(0);
	signal(SIGINT, heredoc_sigint_handler);
	i_list = cmd_list;
	while (i_list)
	{
		((t_command *)i_list->content)->fd = ft_calloc(2, sizeof(int));
		j_list = ((t_command *)i_list->content)->files;
		while (j_list)
		{
			file = (t_file *)j_list->content;
			if (file->type == RED_HEREDOC)
				create_heredoc_file(file, i++);
			j_list = j_list->next;
		}
		i_list = i_list->next;
	}
	dup2(new_stdin, 0);
	signal(SIGINT, sig_handler);
}

void	check_16_heredocs(t_list *cmd_list)
{
	t_list	*cmd_i;
	int		counter;

	cmd_i = cmd_list;
	counter = 0;
	while (cmd_i)
	{
		counter += ((t_command *)cmd_i->content)->tk_count.heredoc_del;
		cmd_i = cmd_i->next;
	}
	if (counter > 16)
	{
		throw_error("maximum here-document count exceeded", 1);
		exit(2);
	}
}
