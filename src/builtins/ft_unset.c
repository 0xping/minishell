/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:17:15 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/25 15:03:57 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

int	unset_one_arg(t_list *i, char **cmd, int j)
{
	t_list	*tmp;

	if (!cmd[1])
		return (1);
	if (!ft_strcmp(((t_env *)i->content)->name, cmd[j]))
	{
		tmp = i;
		g_vars.env = i->next;
		free(tmp->content);
		free(tmp);
		if (!cmd[j + 1])
			return (1);
	}
	return (0);
}

int	_unset(t_list *i, char **cmd, int j)
{
	t_list	*tmp;

	if (!ft_strcmp(((t_env *)i->content)->name, cmd[j]))
	{
		tmp = i;
		if (i->prev)
			i->prev->next = i->next;
		if (i->next)
			i->next->prev = i->prev;
		free(((t_env *)tmp->content)->value);
		free(((t_env *)tmp->content)->name);
		free(tmp->content);
		free(tmp);
		return (1);
	}
	return (0);
}

void	ft_unset(char **cmd)
{
	t_list	*i;
	int		j;

	j = 0;
	while (cmd[++j])
	{
		i = g_vars.env;
		if (i)
		{
			i->prev = NULL;
			if (unset_one_arg(i, cmd, j))
				return ;
			while (i)
			{
				if (_unset(i, cmd, j))
					break ;
				i = i->next;
			}
		}
	}
}
