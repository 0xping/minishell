/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:46:14 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/23 17:56:12 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		parser(t_list *cmds);
int		check_parse_error(t_list *cmds);
void	count_tokens(t_command *cmd);
void	collect_files_and_delimiters(t_command *cmd);
char	*expander(char *word, bool is_heredoc);

#endif
