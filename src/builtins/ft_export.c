/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:14:22 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/15 17:09:50 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

t_list	*dup_env(t_list *_env)
{
	t_list	*i;

	if (!_env)
		return (NULL);
	i = malloc(sizeof(t_list));
	i->content = _env->content;
	i->next = dup_env(_env->next);
	return (i);
}

t_list	*sort_export(void)
{
	t_list	*save;
	t_list	*new;
	t_list	*first;
	t_list	*second;
	void	*exp;

	new = first = dup_env(g_vars.env);
	while (first)
	{
		save = first;
		second = first;
		while (second)
		{
			if (save->content && second->content
				&& ft_strcmp(((t_env *)save->content)->name,
					((t_env *)second->content)->name) > 0)
				save = second;
			second = second->next;
		}
		if (save != first)
		{
			exp = first->content;
			first->content = save->content;
			save->content = exp;
		}
		first = first->next;
	}
	return (new);
}

void	print_export(void)
{
	t_list	*i;
	t_env	*exp;

	i = sort_export();
	while (i)
	{
		exp = (t_env *)i->content;
		ft_putstr_fd("declare -x ", 1);
		write(1, exp->name, ft_strlen(exp->name));
		if (exp->value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(exp->value, 1);
			ft_putchar_fd('"', 1);
		}
		write(1, "\n", 1);
		i = i->next;
	}
	// free i
}

void	ft_export(char **cmd)
{
	if (cmd[1] == NULL)
		print_export();
	else
		fill_my_export(cmd);
}
