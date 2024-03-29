/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:18:46 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/25 16:44:09 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

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
			ft_free((void **)&tmp);
			ft_free((void **)&value);
		}
		else
		{
			if (value)
			{
				ft_free((void **)&env->value);
				env->value = value;
			}
		}
		ft_free((void **)&name);
	}
	else
		ft_lstadd_back(&g_vars.env, ft_lstnew(new_env_node(name, value)));
}

void	ft_env(int wr)
{
	t_list	*i;
	t_env	*content;

	g_vars.exit_status = 0;
	i = g_vars.env;
	while (i)
	{
		content = (t_env *)i->content;
		if (content->value && content->is_set)
		{
			ft_putstr_fd(content->name, wr);
			ft_putchar_fd('=', wr);
			ft_putstr_fd(content->value, wr);
			ft_putchar_fd('\n', wr);
		}
		i = i->next;
	}
}
