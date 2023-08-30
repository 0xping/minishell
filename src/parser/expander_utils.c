/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:08:31 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/30 19:48:33 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	expand_single_token(t_token *token)
{
	char	*tmp;

	tmp = token->value;
	token->value = expander(tmp, false);
	token->is_expanded = ft_strcmp(token->value, tmp);
	free(tmp);
}

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
		data.content = ft_strdup(quote_content);
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
