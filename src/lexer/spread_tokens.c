/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spread_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:08:52 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/06 21:32:22 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

static void	ft_norm(char **p_result, char **p_str);

char	*spread_tokens(char *str) {
  char *tmp;
  char *result;
  char *s;

  result = ft_strdup("");
  s = str;
  while (*s) {
    if ((*s == '<' || *s == '>') && !is_char_quoted(str, s)) {
      tmp = result;
      ft_norm(&result, &s);
      ft_free((void **)&tmp);
    } else
      push_char_to_str(&result, *s);
    s++;
  }
  return (result);
}

static void	ft_norm(char **p_result, char **p_str) {
  char *result;
  char *str;

  result = *p_result;
  str = *p_str;
  if (*str == *(str + 1)) {
    (*str == '<') && (result = ft_strjoin(result, " << "));
    (*str == '>') && (result = ft_strjoin(result, " >> "));
    str++;
  } else {
    (*str == '<') && (result = ft_strjoin(result, " < "));
    (*str == '>') && (result = ft_strjoin(result, " > "));
  }
  *p_result = result;
  *p_str = str;
}
