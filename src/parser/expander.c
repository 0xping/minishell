/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/25 15:19:23 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

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

char	*get_value(char *name, int *len)
{
	t_env	*env_node;
	char	*var_name;
	int		i;

	i = 0;
	while (name[i] && !is_char_special(name[i]) && !ft_isdigit(name[i]))
		i++;
	*len = i + ft_isdigit(name[i]);
	var_name = ft_substr(name, 0, i);
	env_node = get_env_by_name(var_name);
	if (env_node)
		return (ft_free((void **)&var_name), ft_strdup(env_node->value));
	return (ft_free((void **)&var_name), ft_strdup(""));
}

char	*expand_dollar(char *word, bool expand_sq, bool is_heredoc)
{
	t_expand_data	dt;
	char			*tmp;
	int				len;
	char			*result;

	char *(*ex)(char *, bool) = expander;
	if (expand_sq)
		ex = _expander;
	dt.before = ft_substr(word, 0, ft_strchr(word, '$') - word);
	dt.content = get_value(ft_strchr(word, '$') + 1, &len);
	if (len == 0)
	{
		if (word[ft_strlen(dt.before) + 1] == '?')
		{
			free(dt.content);
			dt.content = ft_itoa(g_vars.exit_status);
			len++;
		}
		else if ((word[ft_strlen(dt.before) + 1] != '"'
				&& word[ft_strlen(dt.before) + 1] != '\'') || is_heredoc)
		{
			free(dt.content);
			dt.content = ft_strdup("$");
		}
	}
	tmp = ft_strdup(ft_strchr(word, '$') + len + 1);
	dt.after = ex(tmp, false);
	result = join_strings((char *[]){dt.before, dt.content, dt.after}, 3, "");
	return (free(tmp), free(dt.before), free(dt.content), free(dt.after),
		result);
}

char	*expand_sq(char *word, bool is_heredoc)
{
	t_expand_data	data;
	char			*tmp;
	char			*quote_content;
	char			*result;

	data.before = ft_substr(word, 0, ft_strchr(word, '\'') - word);
	quote_content = get_quote_content(ft_strchr(word, '\''));
	if (is_heredoc)
		data.content = expander(quote_content, is_heredoc);
	else
		data.content = quote_content;
	tmp = ft_strdup(ft_strchr(word, '\'') + ft_strlen(quote_content) + 2);
	data.after = expander(tmp, is_heredoc);
	ft_free((void **)&tmp);
	result = join_strings((char *[]){data.before, data.content, data.after}, 3,
		"'");
	return (free(quote_content), free(data.before), free(data.content),
		free(data.after), result);
}

char	*expand_dq(char *word)
{
	t_expand_data	data;
	char			*tmp;
	char			*result;
	char			*quote_content;

	data.before = ft_substr(word, 0, ft_strchr(word, '"') - word);
	quote_content = get_quote_content(ft_strchr(word, '"'));
	data.content = _expander(quote_content, false);
	tmp = ft_strdup(ft_strchr(word, '"') + ft_strlen(quote_content) + 2);
	data.after = expander(tmp, false);
	ft_free((void **)&tmp);
	result = join_strings((char *[]){data.before, data.content, data.after}, 3,
		"\"");
	return (free(quote_content), free(data.before), free(data.content),
		free(data.after), result);
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
		if (word[i] == '$' && word[i + 1])
			return (expand_dollar(word, false, is_heredoc));
		if (word[i] == '\'')
			return (expand_sq(word, is_heredoc));
		if (word[i] == '"')
			return (expand_dq(word));
		i++;
	}
	return (ft_strdup(word));
}
