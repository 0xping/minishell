/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/03 16:38:18 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	special_chars(t_expand_data *dt, char *word, bool is_heredoc, int *len)
{
	if (word[ft_strlen(dt->before) + 1] == '?')
	{
		free(dt->content);
		dt->content = ft_itoa(g_vars.exit_status);
		(*len)++;
	}
	else if ((word[ft_strlen(dt->before) + 1] != '"'
			&& word[ft_strlen(dt->before) + 1] != '\'') || is_heredoc)
	{
		free(dt->content);
		dt->content = ft_strdup("$");
	}
}

char	*expand_dollar(char *word, bool expand_sq, bool is_heredoc)
{
	t_expand_data	dt;
	char			*tmp;
	int				len;
	char			*result;
	char			*(*ex)(char *, bool);

	ex = expander;
	if (expand_sq)
		ex = _expander;
	dt.before = ft_substr(word, 0, ft_strchr(word, '$') - word);
	dt.content = get_value(ft_strchr(word, '$') + 1, &len);
	if (len == 0)
		special_chars(&dt, word, is_heredoc, &len);
	tmp = ft_strdup(ft_strchr(word, '$') + len + 1);
	dt.after = ex(tmp, false);
	result = join_strings((char *[]){dt.before, dt.content, dt.after}, 3, "");
	return (free(tmp), free(dt.before), free(dt.content), free(dt.after),
		result);
}

char	*_expander(char *word, bool is_heredoc)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if (word[i] == '$')
			return (expand_dollar(word, true, is_heredoc));
		i++;
	}
	return (ft_strdup(word));
}

char	*expander(char *word, bool is_heredoc)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if (is_heredoc)
			return (_expander(word, is_heredoc));
		else if (word[i] == '$' && word[i + 1])
			return (expand_dollar(word, false, is_heredoc));
		else if (word[i] == '\'' && ft_strchr(word + i + 1, word[i]))
			return (expand_sq(word, is_heredoc));
		else if (word[i] == '"' && ft_strchr(word + i + 1, word[i]))
			return (expand_dq(word));
		i++;
	}
	return (ft_strdup(word));
}
