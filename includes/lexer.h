/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:13:46 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/27 19:33:55 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

void		add_new_token(t_list **lst_tokens, char *token);
t_command	*create_command_node(char *cmd);
char		*spread_tokens(char *str);
t_list		*lexer(char *input);

#endif
