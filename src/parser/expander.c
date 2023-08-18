/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/18 13:16:01 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

char	*get_var_value(char *var, int *ptr_i, bool is_heredoc)
{
	int		i;
	char	*var_name;
	t_env	*env_node;
	char	*var_as_str;
	char	*s;

	i = 0;
	while (var[i] && !is_char_special(var[i]))
		i++;
	*ptr_i += i;
	var_name = ft_substr(var, 0, i);
	if (*var_name == 0)
	{
		*ptr_i += 1;
		if ((var[i] == '"' || var[i] == '\'') && ft_strchr(&var[i + 1], var[i])
				&& !is_heredoc)
			return (ft_free((void **)&var_name), ft_strdup(""));
		if (var[i] == '?')
			return (ft_free((void **)&var_name), ft_itoa(g_vars.exit_status));
		var_as_str = char_to_str(var[i]);
		s = ft_strjoin("$", var_as_str);
		return (ft_free((void **)&var_name), ft_free((void **)&var_as_str), s);
	}
	env_node = get_env_by_name(var_name);
	if (env_node)
		return (ft_free((void **)&var_name), ft_strdup(env_node->value));
	return (ft_free((void **)&var_name), ft_strdup(""));
}

bool	should_expand(char *str, char *dollar_ptr)
{
	int		i;
	bool	result;
	bool	single_quoted;
	bool	double_quoted;

	i = 0;
	result = true;
	single_quoted = false;
	double_quoted = false;
	while (str + i < dollar_ptr)
	{
		if (str[i] == '\'' && !double_quoted)
			single_quoted = !single_quoted;
		else if (str[i] == '"' && !single_quoted)
			double_quoted = !double_quoted;
		i++;
	}
	if (single_quoted)
		result = false;
	return (result);
}

void	freeable_join(char **s1, char *s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = ft_strjoin(tmp, s2);
	ft_free((void **)&tmp);
	ft_free((void **)&s2);
}

// char	*expander(char *word, bool is_heredoc)
// {
// 	int		i;
// 	char	*result;

// 	i = 0;
// 	result = ft_strdup("");
// 	while (word[i])
// 	{
// 		if (word[i] == '$' && word[i + 1] && (is_heredoc || should_expand(word,
// 					word + i)))
// 		{
// 			if ((word[i + 1] == '\"' || word[i + 1] == '"') && is_heredoc)
// 				push_char_to_str(&result, '$');
// 			else
// 				freeable_join(&result, get_var_value(&word[i + 1], &i));
// 		}
// 		else
// 			push_char_to_str(&result, word[i]);
// 		i++;
// 	}
// 	return (result);
// }

char	*expander(char *word, bool is_heredoc)
{
	int		i;
	char	*result;

	i = 0;
	result = ft_strdup("");
	while (word[i])
	{
		if (word[i] == '$' && word[i + 1] && (is_heredoc || should_expand(word,
					word + i)))
			freeable_join(&result, get_var_value(word + i + 1, &i, is_heredoc));
		else
			push_char_to_str(&result, word[i]);
		i++;
	}
	return (result);
}

// char	*expander(char *word, bool expand)
// {
// 	int		i;
// 	char	*result;

// 	i = 0;
// 	result = ft_strdup("");
// 	while (word[i])
// 	{
// 		if (word[i] == '$' && word[i + 1] && expand && should_expand(word,
// 				word + i))
// 			freeable_join(&result, get_var_value(word + i + 1, &i));
// 		else
// 			push_char_to_str(&result, word[i]);
// 		i++;
// 	}
// 	return (result);
// }
