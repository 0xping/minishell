/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/22 16:28:57 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

typedef struct s_expand_data
{
	char	*before;
	char	*content;
	char	*after;
}			t_expand_data;

char	*get_value(char *name, int *len)
{
	t_env	*env_node;
	char	*var_name;
	int		i;

	i = 0;
	while (name[i] && !is_char_special(name[i]))
		i++;
	*len = i;
	var_name = ft_substr(name, 0, i);
	env_node = get_env_by_name(var_name);
	if (env_node)
		return (ft_free((void **)&var_name), ft_strdup(env_node->value));
	return (ft_free((void **)&var_name), ft_strdup(""));
}

char	*expand_dollar(char *word, bool is_heredoc)
{
	t_expand_data	dt;
	char			*tmp;
	int				len;
	char			*result;

	dt.before = ft_substr(word, 0, ft_strchr(word, '$') - word);
	dt.content = get_value(ft_strchr(word, '$') + 1, &len);
	if (len == 0)
	{
		if (word[len + 1] == '?')
		{
			free(dt.content);
			dt.content = ft_itoa(g_vars.exit_status);
			len++;
		}
		else if ((word[len + 1] != '"' && word[len + 1] != '\'') || is_heredoc)
		{
			free(dt.content);
			dt.content = ft_strdup("$");
		}
	}
	tmp = ft_strdup(ft_strchr(word, '$') + len + 1);
	dt.after = expander(tmp, false, false);
	result = join_strings((char *[]){dt.before, dt.content, dt.after}, 3, "");
	return (free(tmp), free(dt.before), free(dt.content), free(dt.after),
		result);
}

char	*expand_sq(char *word, bool expand, bool is_heredoc)
{
	t_expand_data	data;
	char			*tmp;
	char			*quote_content;
	char			*result;

	data.before = ft_substr(word, 0, ft_strchr(word, '\'') - word);
	quote_content = get_quote_content(ft_strchr(word, '\''));
	if (expand || is_heredoc)
	{
		data.content = expander(quote_content, false, is_heredoc);
		free(quote_content);
	}
	else
		data.content = quote_content;
	tmp = ft_strdup(ft_strchr(word, '\'') + ft_strlen(data.content) + 2);
	data.after = expander(tmp, expand, is_heredoc);
	ft_free((void **)&tmp);
	result = join_strings((char *[]){data.before, data.content, data.after}, 3,
			"'");
	return (free(data.before), free(data.content), free(data.after), result);
}

char	*expand_dq(char *word)
{
	t_expand_data	data;
	char			*tmp;
	char			*result;
	char			*quote_content;

	data.before = ft_substr(word, 0, ft_strchr(word, '"') - word);
	quote_content = get_quote_content(ft_strchr(word, '"'));
	data.content = expander(quote_content, false, false);
	tmp = ft_strdup(ft_strchr(word, '"') + ft_strlen(quote_content) + 2);
	data.after = expander(tmp, false, false);
	ft_free((void **)&tmp);
	result = join_strings((char *[]){data.before, data.content, data.after}, 3,
			"\"");
	return (free(quote_content), free(data.before), free(data.content),
		free(data.after), result);
}

char	*expander(char *word, bool expand, bool is_heredoc)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if (word[i] == '$')
			return (expand_dollar(word, is_heredoc));
		if (word[i] == '\'')
			return (expand_sq(word, expand, is_heredoc));
		if (word[i] == '"')
			return (expand_dq(word));
		i++;
	}
	return (ft_strdup(word));
}
