/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:14:22 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/19 17:03:24 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

t_list	*dup_env(t_list *_env)
{
	t_list	*i;

	if (!_env)
		return (NULL);
	i = ft_lstnew(new_env_node(((t_env *)_env->content)->name,
			((t_env *)_env->content)->value));
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

	new = dup_env(g_vars.env);
	first = new;
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

void	print_export(int wr)
{
	t_list	*export_list;
	t_list	*i;
	t_env	*exp;

	export_list = sort_export();
	i = export_list;
	while (i)
	{
		exp = (t_env *)i->content;
		ft_putstr_fd("declare -x ", wr);
		write(1, exp->name, ft_strlen(exp->name));
		if (exp->value)
		{
			ft_putstr_fd("=\"", wr);
			ft_putstr_fd(exp->value, wr);
			ft_putchar_fd('"', wr);
		}
		write(1, "\n", wr);
		i = i->next;
	}
	ft_lstclear(&export_list, del_env);
}

void	ft_export(char **cmd, int wr)
{
	if (cmd[1] == NULL)
		print_export(wr);
	else
		fill_my_export(cmd);
}
