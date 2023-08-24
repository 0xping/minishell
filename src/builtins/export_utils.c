/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:17:47 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/24 15:16:38 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

typedef struct s_export
{
	char	*name;
	char	*value;
	int		concat;
}			t_export;

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

void	dupoin(t_export *exp, char **cmd, int j, long long lent)
{
	if (ft_strchr(cmd[j], '='))
	{
		exp->name = ft_substr(cmd[j], 0, lent - (lent && cmd[j][lent - 1] == '+'));
		exp->value = ft_strdup(ft_strchr(cmd[j], '=') + 1);
		exp->concat = (lent && cmd[j][lent - 1] == '+');
	}
	else
	{
		exp->name = ft_strdup(cmd[j]);
		exp->concat = 0;
		exp->value = 0;
		if (lent == 0)
			exp->value = ft_strdup("");
	}
}

void	fill_my_export(char **cmd)
{
	long long	lent;
	int			j;
	t_export	*exp;

	exp = malloc(sizeof(t_export));
	j = 0;
	while (cmd[++j])
	{
		lent = ft_strchr(cmd[j], '=') - cmd[j];
		dupoin(exp, cmd, j, lent);
		if (!check_export_errors(cmd[j], exp->name))
			upsert_env_node(ft_strdup(exp->name), exp->value, exp->concat);
		else
			ft_free((void **)&exp->value);
		ft_free((void **)&exp->name);
	}
	free(exp);
	set_global_envp();
}
