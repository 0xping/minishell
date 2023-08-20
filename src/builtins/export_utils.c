/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:17:47 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/19 15:53:49 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

int	check_export_errors(char *ind, char *name)
{
	int	i;

	i = 0;

	while (name[i] || !*name)
	{
		if (!*name || is_char_special(name[i]) || ft_isdigit(name[0]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(ind, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_vars.exit_status = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	fill_my_export(char **cmd)
{
	int		lent;
	int		_concat;
	int		j;
	char	*_name;
	char	*_value;

	j = 0;
	while (cmd[++j])
	{
		lent = ft_strchr(cmd[j], '=') - cmd[j];
		if (lent > 0)
		{
			_name = ft_substr(cmd[j], 0, lent - (cmd[j][lent - 1] == '+'));
			_value = ft_strdup(ft_strchr(cmd[j], '=') + 1);
			_concat = (cmd[j][lent - 1] == '+');
		}
		else
		{
			_name = ft_strdup(cmd[j]);
			_concat = 0;
			_value = 0;
			if (lent == 0)
				_value = ft_strdup("");
		}
		if (!check_export_errors(cmd[j], _name))
			upsert_env_node(ft_strdup(_name), _value, _concat);
		else
			ft_free((void **)&_value);
		ft_free((void **)&_name);
	}
}

//"$?$"
// if (lent > 0)
// {
// 	_value = ft_strdup(ft_strchr(cmd[j], '=') + 1);
// 	_name = ft_substr(cmd[j], 0, lent - (cmd[j][lent - 1] == '+'));
// 	upsert_env_node(_name, _value, (cmd[j][lent - 1] == '+'));
// }
// else if (lent == 0)
// 	upsert_env_node(ft_strdup(cmd[j]), ft_strdup(""), 0);
// else
// 	upsert_env_node(ft_strdup(cmd[j]), 0, 0);