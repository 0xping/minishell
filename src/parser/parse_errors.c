/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:32:05 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/06 18:50:32 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_parse_error(t_list *cmds)
{
	t_list		*i;
	t_command	*content;

	i = cmds;
	while (i)
	{
		content = ((t_command *)i->content);
		count_tokens(content);
		if (check_quotes(content->value))
		{
			throw_error("minishell: unclosed quote", 1);
			return (0);
		}
		if (!ft_strlen(content->value)
			|| content->tk_count.append_file != content->tk_count.append_op
			|| content->tk_count.heredoc_del != content->tk_count.heredoc_op
			|| content->tk_count.in_file != content->tk_count.in_op
			|| content->tk_count.out_file != content->tk_count.out_op)
		{
			throw_error("minishell: parse error", 258);
			return (0);
		}
		i = i->next;
	}
	return (1);
}

void	count_tokens(t_command *cmd)
{
	t_list	*token;
	t_token	*content;

	token = cmd->lst_tokens;
	while (token)
	{
		content = token->content;
		(content->type == TK_APPEND_FILE) && (cmd->tk_count.append_file++);
		(content->type == TK_APPEND_OP) && (cmd->tk_count.append_op++);
		(content->type == TK_REDIRECT_IN_FILE) && (cmd->tk_count.in_file++);
		(content->type == TK_REDIRECT_IN_OP) && (cmd->tk_count.in_op++);
		(content->type == TK_REDIRECT_OUT_FILE) && (cmd->tk_count.out_file++);
		(content->type == TK_REDIRECT_OUT_OP) && (cmd->tk_count.out_op++);
		(content->type == TK_HEREDOC_DEL) && (cmd->tk_count.heredoc_del++);
		(content->type == TK_HEREDOC_OP) && (cmd->tk_count.heredoc_op++);
		token = token->next;
	}
}
