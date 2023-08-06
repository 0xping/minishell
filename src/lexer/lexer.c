/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:13:48 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/06 19:04:17 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_new_token(t_list **lst_tokens, char *token)
{
	t_token		*new_token;
	token_type	prev_token;

	prev_token = -1;
	if (ft_lstsize(*lst_tokens))
		prev_token = ((t_token *)(ft_lstlast(*lst_tokens)->content))->type;
	new_token = ft_calloc(1, sizeof(t_token));
	if (!ft_strcmp(token, ">>"))
		new_token->type = TK_APPEND_OP;
	else if (!ft_strcmp(token, "<<"))
		new_token->type = TK_HEREDOC_OP;
	else if (!ft_strcmp(token, "<"))
		new_token->type = TK_REDIRECT_IN_OP;
	else if (!ft_strcmp(token, ">"))
		new_token->type = TK_REDIRECT_OUT_OP;
	else
	{
		if (prev_token == TK_APPEND_OP)
			new_token->type = TK_APPEND_FILE;
		else if (prev_token == TK_HEREDOC_OP)
			new_token->type = TK_HEREDOC_DEL;
		else if (prev_token == TK_REDIRECT_IN_OP)
			new_token->type = TK_REDIRECT_IN_FILE;
		else if (prev_token == TK_REDIRECT_OUT_OP)
			new_token->type = TK_REDIRECT_OUT_FILE;
		else
			new_token->type = TK_WORD;
	}
	new_token->value = ft_strdup(token);
	ft_lstadd_back(lst_tokens, ft_lstnew(new_token));
}

t_command	*create_command_node(char *cmd)
{
	t_command	*command;
	char		**tokens;
	int			i;

	command = ft_calloc(1, sizeof(t_command));
	command->value = ft_strdup(cmd);
	tokens = split_quote_safe(cmd, "\t\n\v\f\r ", 0);
	i = 0;
	while (tokens[i])
	{
		add_new_token(&command->lst_tokens, tokens[i]);
		ft_free((void **)&tokens[i++]);
	}
	ft_free((void **)&tokens);
	return (command);
}

t_list	*lexer(char *input)
{
	char	**pipes;
	int		i;
	t_list	*commands;

	i = 0;
	commands = 0;
	pipes = split_quote_safe(input, "|", 1);
	while (pipes[i])
	{
		ft_lstadd_back(&commands, ft_lstnew(create_command_node(pipes[i])));
		ft_free((void **)&pipes[i++]);
	}
	ft_free((void **)&pipes);
	return (commands);
}
