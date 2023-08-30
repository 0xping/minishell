/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:46:14 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/30 16:40:12 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int			parser(t_list *cmds);
int			check_parse_error(t_list *cmds);
void		count_tokens(t_command *cmd);
void		collect_files_and_delimiters(t_command *cmd);

/*---------------------------- Expand ------------------------*/
typedef struct s_expand_data
{
	char	*before;
	char	*content;
	char	*after;
}			t_expand_data;

char		*get_value(char *name, int *len);
char		*expand_dollar(char *word, bool expand_sq, bool is_heredoc);
char		*expand_sq(char *word, bool is_heredoc);
char		*expand_dq(char *word);
char		*_expander(char *word, bool is_heredoc);
char		*expander(char *word, bool is_heredoc);
void		expand_single_token(t_token *token);

#endif
