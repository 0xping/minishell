/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:47:10 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/03 21:29:53 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	ft_free(void *ptr);
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

#endif
