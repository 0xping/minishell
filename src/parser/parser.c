/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:25:59 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/16 17:16:21 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

static int is_ambiguous(char *s)
{
	char **sp = split_quote_safe(s, "\t\n\v\f\r ", 0);
	int i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	return (i > 1 || !ft_strlen(s));
}



static void	expand_tokens(t_command *cmd)
{
	t_list	*lst_token;
	t_token	*token;
	char	*tmp;

	lst_token = cmd->lst_tokens;
	while (lst_token)
	{
		token = (t_token *)lst_token->content;
		if(token->type != TK_HEREDOC_DEL)
		{
			tmp = token->value;
			token->value = expander(token->value, 0);
			if((token->type == TK_APPEND_FILE || token->type == TK_REDIRECT_IN_FILE || token->type == TK_REDIRECT_OUT_FILE) && ft_strcmp(tmp, token->value))
			{
				if(is_ambiguous(token->value))
				{
					throw_error("ambiguous redirect", 1);
					cmd->file_error = 1;
				}
			}
			ft_free((void **)&tmp);
		}
		lst_token = lst_token->next;
	}
}






static void remove_quotes_from_tk(t_command * cmd)
{
	t_list	*lst_token;
	t_token	*token;
	char	*tmp;

	lst_token = cmd->lst_tokens;
	while (lst_token)
	{
		token = (t_token *)lst_token->content;
		tmp = token->value;
		token->value = remove_quotes(token->value);
		ft_free((void **)&tmp);
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
