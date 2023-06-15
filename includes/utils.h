/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:47:10 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/06/15 13:30:19 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		is_char_quoted(char *str, char *pos);
char	*get_prompt(void);
int		is_blank(char *str);
char	check_quotes(char *str);
char	*join_strings(char **arr, int size, char *sep);
void	trow_error(char *msg, int err_code);

#endif
