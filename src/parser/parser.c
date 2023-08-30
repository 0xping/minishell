/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:25:59 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/30 17:18:59 by aait-lfd         ###   ########.fr       */
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

static int	is_file_tk(t_token_type tk_type)
{
	return ((tk_type == TK_APPEND_FILE || tk_type == TK_REDIRECT_IN_FILE
			|| tk_type == TK_REDIRECT_OUT_FILE));
}

static void	expand_tokens(t_command *cmd)
{
	t_list	*lst_token;
	t_token	*token;

	lst_token = cmd->lst_tokens;
	while (lst_token)
	{
		token = (t_token *)lst_token->content;
		if (token->type != TK_HEREDOC_DEL)
		{
			expand_single_token(token);
			if (is_file_tk(token->type) && token->is_expanded
				&& is_ambiguous(token->value))
			{
				throw_error("ambiguous redirect", 1);
				cmd->file_error = 1;
			}
		}
		lst_token = lst_token->next;
	}
}

void	remove_quotes_from_tk(t_command *cmd)
{
	t_list	*lst_token;
	t_token	*token;
	char	*tmp;

	lst_token = cmd->lst_tokens;
	while (lst_token)
	{
		token = (t_token *)lst_token->content;
		if (token->type != TK_HEREDOC_DEL && token->type != TK_WORD)
		{
			tmp = token->value;
			token->value = remove_quotes(token->value);
			ft_free((void **)&tmp);
		}
		lst_token = lst_token->next;
	}
}

int	parser(t_list *cmd_list)
{
	t_list		*cmd_i;
	t_command	*cmd_node;

	if (!check_parse_error(cmd_list))
		return (0);
	cmd_i = cmd_list;
	while (cmd_i)
	{
		cmd_node = (t_command *)cmd_i->content;
		expand_tokens(cmd_node);
		remove_quotes_from_tk(cmd_node);
		collect_files_and_delimiters(cmd_node);
		cmd_i = cmd_i->next;
	}
	return (1);
}
