/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:16:59 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/25 16:53:56 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

bool	is_n_option(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (false);
	if (str[i] != '-')
		return false;
	i++;
	while (str[i] == 'n')
		i++;
	return (str[i] == 0);
}

void	ft_echo(char **args, int wr)
{
	int		i;
	bool	n_flag;

	g_vars.exit_status = 0;
	i = 0;
	n_flag = false;
	while (args[i] && is_n_option(args[i]))
	{
		n_flag = true;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], wr);
		if (args[i + 1])
			ft_putchar_fd(' ', wr);
		i++;
	}
	if (!n_flag)
		ft_putchar_fd('\n', wr);
}
