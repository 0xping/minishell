/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:47:10 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/17 12:07:02 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	ft_free(void **ptr);
int		is_char_quoted(char *str, char *pos);
char	*get_prompt(void);
int		is_blank(char *str);
char	check_quotes(char *str);
char	*join_strings(char **arr, int size, char *sep);
void	trow_error(char *msg, int err_code);
int		index_of(char *str, char c);
char	**split_quote_safe(char *cmd, char *dels, bool handle_empty_str);
int		char_count(char *str, char c);
char	*char_to_str(char c);
void	throw_error(char *msg, int err_code);
int		push_str(char ***ptr_arr, char *str);
int		is_char_single_quoted(char *str, char *pos);
int		is_char_double_quoted(char *str, char *pos);
void	push_char_to_str(char **str, char c);
char	*get_quote_content(char *s);
char	*remove_quotes(char *s);
bool	is_char_special(char c);

#endif
