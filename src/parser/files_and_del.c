/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_and_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:05:36 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/02 17:12:43 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

static int	is_ambiguous(char *s)
{
	char	**sp;
	int		i;

	sp = split_quote_safe(s, "\t\n\v\f\r ", 0);
	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	return (i > 1 || !ft_strlen(s));
}

static char	*get_file_name(t_token *token)
{
	char	*no_quotes;

	no_quotes = remove_quotes(token->value);
	if (token->is_expanded && is_ambiguous(token->value))
	{
		free(no_quotes);
		return (0);
	}
	else
		return (no_quotes);
}

t_file	*init_file(t_token *token, t_red_type type)
{
	t_file	*file;

	file = ft_calloc(1, sizeof(t_file));
	file->name = get_file_name(token);
	file->type = type;
	return (file);
}

static void	push_words_to_cmd(t_command *cmd, t_token *token)
{
	char	*no_quotes;
	char	**sp;
	int		i;

	no_quotes = remove_quotes(token->value);
	i = 0;
	if (token->is_expanded)
	{
		if (ft_strlen(no_quotes))
		{
			sp = split_quote_safe(no_quotes, "\t\n\v\f\r ", 0);
			while (sp[i])
				push_str(&cmd->command, sp[i++]);
			free(no_quotes);
			free(sp);
		}
		else if (ft_strcmp(no_quotes, token->value))
			push_str(&cmd->command, no_quotes);
		else
			free(no_quotes);
	}
	else
		push_str(&cmd->command, no_quotes);
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
			ft_lstadd_back(&cmd->files, ft_lstnew(init_file(token,
						RED_APPEND)));
		if (token->type == TK_REDIRECT_IN_FILE)
			ft_lstadd_back(&cmd->files, ft_lstnew(init_file(token, RED_IN)));
		if (token->type == TK_REDIRECT_OUT_FILE)
			ft_lstadd_back(&cmd->files, ft_lstnew(init_file(token, RED_OUT)));
		if (token->type == TK_HEREDOC_DEL)
			ft_lstadd_back(&cmd->files, ft_lstnew(init_file(token,
						RED_HEREDOC)));
		if (token->type == TK_WORD)
			push_words_to_cmd(cmd, token);
		lst_token = lst_token->next;
	}
}
