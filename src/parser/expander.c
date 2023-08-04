/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:25 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/04 00:41:03 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_char_special(char c)
{
	char	*special_characters;

	special_characters = "$!#%*(){}[]\"'|\\;:,<>?&=+-n \t \n";
	return (ft_strchr(special_characters, c));
}

char	*get_var_value(char *var, int *ptr_i)
{
	int		i;
	char	*var_name;
	t_env	*env_node;

	i = 0;
	while (var[i] && !is_char_special(var[i]))
		i++;
	*ptr_i += i;
	var_name = ft_substr(var, 0, i);
	env_node = get_env_by_name(var_name);
	free(var_name);
	if (env_node)
		return (ft_strdup(env_node->value));
	return (ft_strdup(""));
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
	ft_free(tmp);
	ft_free(s2);
}

char	*expander(char *word, bool expand)
{
	int		i;
	char	*result;

	i = 0;
	result = ft_strdup("");
	while (word[i])
	{
		if (word[i] == '"' || word[i] == '\'')
		{
			if (is_char_quoted(word, word + i))
			{
				push_char_to_str(&result, word[i]);
				word[i] *= -1;
			}
		}
		else if (word[i] == '$' && expand && should_expand(word, word + i))
			freeable_join(&result, get_var_value(word + i + 1, &i));
		else
			push_char_to_str(&result, word[i]);
		i++;
	}
	return (result);
}
