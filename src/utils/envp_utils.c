/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:06:15 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/23 12:05:01 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	free_global_envp(void)
{
	int	i;

	i = 0;
	while (g_vars.envp && g_vars.envp[i])
	{
		ft_free((void **)(g_vars.envp + i));
		i++;
	}
	ft_free((void **)&g_vars.envp);
}

void	set_global_envp(void)
{
	t_list	*i_env;
	t_env	*env_content;
	int		i;

	i_env = g_vars.env;
	free_global_envp();
	g_vars.envp = ft_calloc(sizeof(char *), ft_lstsize(g_vars.env) + 1);
	i = 0;
	while (i_env)
	{
		env_content = (t_env *)i_env->content;
		g_vars.envp[i] = join_strings((char *[]){env_content->name,
				env_content->value}, 2, "=");
		i++;
		i_env = i_env->next;
	}
}
