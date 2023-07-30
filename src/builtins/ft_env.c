/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:18:46 by m-boukel          #+#    #+#             */
/*   Updated: 2023/07/30 02:45:53 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*new_env_node(char *name, char *value)
{
	t_env	*result;

	result = ft_calloc(sizeof(t_env), 1);
	result->name = name;
	result->value = value;
	result->is_set = 1;
	return (result);
}

t_list	*create_env_list(const char *envp[])
{
	int		i;
	char	*equal_pos;
	t_list	*head;
	char	*name;
	char	*value;

	i = 0;
	head = NULL;
	while (envp[i])
	{
		equal_pos = ft_strchr(envp[i], '=');
		name = ft_substr(envp[i], 0, equal_pos - envp[i]);
		value = ft_strdup(equal_pos + 1);
		ft_lstadd_back(&head, ft_lstnew(new_env_node(name, value)));
		i++;
	}
	return (head);
}

t_env	*get_env_by_name(char *name)
{
	t_list	*i;
	t_env	*content;

	i = g_vars.env;
	while (i)
	{
		content = (t_env *)i->content;
		if (!ft_strcmp(name, content->name))
			return (content);
		i = i->next;
	}
	return (0);
}

void	upsert_env_node(char *name, char *value, bool concat_value)
{
	t_env	*env;
	char	*tmp;

	env = get_env_by_name(name);
	if (env)
	{
		if (concat_value)
		{
			tmp = env->value;
			env->value = ft_strjoin(env->value, value);
			ft_free(env);
		}
		else
		{
			ft_free(env->value);
			env->value = ft_strdup(value);
		}
	}
	else
		ft_lstadd_back(&g_vars.env, ft_lstnew(new_env_node(name, value)));
}

void	ft_env(int fd)
{
	t_list	*i;
	t_env	*content;

	i = g_vars.env;
	while (i)
	{
		content = (t_env *)i->content;
		if (content->value && content->is_set)
		{
			ft_putstr_fd(content->name, fd);
			ft_putchar_fd('=', fd);
			ft_putstr_fd(content->value, fd);
		}
		ft_putchar_fd('\n', fd);
		i = i->next;
	}
}
