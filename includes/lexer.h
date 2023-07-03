/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:13:46 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/03 20:21:43 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum
{
	TK_APPEND_OP,         // Append operator (>>)
	TK_APPEND_FILE,       // File to append to (>>)
	TK_HEREDOC_OP,        // Here-document operator (<<)
	TK_HEREDOC_DEL,       // Here-document delimiter (<<)
	TK_REDIRECT_OUT_OP,   // Output redirection operator (>)
	TK_REDIRECT_OUT_FILE, // Output file (>)
	TK_REDIRECT_IN_OP,    // Input redirection operator (<)
	TK_REDIRECT_IN_FILE,  // Input file (<)
	TK_WORD,              // others
}				token_type;

typedef struct s_command
{
	char		*value;
	t_list		*lst_tokens;
}				t_command;

typedef struct s_token
{
	char		*value;
	token_type	type;
}				t_token;

void			add_new_token(t_list **lst_tokens, char *token);
t_command		*create_command_node(char *cmd);
char			*spread_tokens(char *str);
t_list			*lexer(char *input);
void			del_command(void *content);
void			del_tokens(void *content);

#endif
