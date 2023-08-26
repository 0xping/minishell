/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:17:15 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/26 15:45:56 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	del_env_node(t_list *del)
{
	t_list	**head;

	head = &g_vars.env;
	if (*head == 0 || del == 0)
		return ;
	if (*head == del)
		*head = del->next;
	if (del->next)
		(del->next)->prev = del->prev;
	if (del->prev)
		(del->prev)->next = del->next;
	free(((t_env *)del->content)->name);
	free(((t_env *)del->content)->value);
	free(del->content);
	free(del);
}

void	unset_var(char *var)
{
	t_list	*i;
	t_env	*content;

	i = g_vars.env;
	while (i)
	{
		content = (t_env *)i->content;
		if (!ft_strcmp(get_env_by_name(var)->name, content->name))
		{
			del_env_node(i);
			break ;
		}
		i = i->next;
	}
}

void	ft_unset(char **cmd)
{
	int	i;

	i = 0;
	g_vars.exit_status = 0;
	while (cmd[++i])
	{
		if (get_env_by_name(cmd[i]))
			unset_var(cmd[i]);
	}
}
