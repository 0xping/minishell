/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:17:47 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/15 17:11:43 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	check_export_errors(char **cmd)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (cmd[i])
	{
		while (cmd[i][j])
		{
			if (cmd[i][0] != '_' && !ft_isalpha(cmd[i][0]))
			{
				write(2, "minishell: export: `", 20);
				write(2, cmd[i], ft_strlen(cmd[i]));
				write(2, "': not a valid identifier\n", 26);
			}
			j++;
		}
		i++;
	}
}

void	fill_my_export(char **cmd)
{
	int		lent;
	int		j;
	char	*_name;
	char	*_value;

	j = 0;
	check_export_errors(cmd);
	while (cmd[++j])
	{
		lent = ft_strchr(cmd[j], '=') - cmd[j];
		if (lent > 0)
		{
			_value = ft_strdup(ft_strchr(cmd[j], '=') + 1);
			_name = ft_substr(cmd[j], 0, lent - (cmd[j][lent - 1] == '+'));
			upsert_env_node(_name, _value, (cmd[j][lent - 1] == '+'));
		}
		else if (lent == 0)
			upsert_env_node(ft_strdup(cmd[j]), ft_strdup(""), 0);
		else
			upsert_env_node(ft_strdup(cmd[j]), 0, 0);
	}
}
