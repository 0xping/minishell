/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_and_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:05:36 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/07 19:58:32 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_file	*init_file(char *name, red_type type)
{
	t_file	*file;

	file = ft_calloc(1, sizeof(t_file));
	file->name = name;
	file->type = type;
	return (file);
}

void	collect_files_and_delimiters(t_command *cmd)
{
	t_list	*lst_token;
	t_token	*token;

	lst_token = cmd->lst_tokens;
	while (lst_token)
	{
		token = (t_token *)lst_token->content;
		if (token->type == TK_APPEND_FILE)
			ft_lstadd_back(&cmd->files, ft_lstnew(init_file(token->value,
							RED_APPEND)));
		if (token->type == TK_REDIRECT_IN_FILE)
			ft_lstadd_back(&cmd->files, ft_lstnew(init_file(token->value,
							RED_IN)));
		if (token->type == TK_REDIRECT_OUT_FILE)
			ft_lstadd_back(&cmd->files, ft_lstnew(init_file(token->value,
							RED_OUT)));
		if (token->type == TK_HEREDOC_DEL)
			ft_lstadd_back(&cmd->files, ft_lstnew(init_file(token->value,
							RED_HEREDOC)));
		if (token->type == TK_WORD)
			push_str(&cmd->command, token->value);
		lst_token = lst_token->next;
	}
}
