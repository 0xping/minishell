/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:16:59 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/04 19:02:11 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_n_option(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (false);
	if (str[i] == '-')
		i++;
	while (str[i] == 'n')
		i++;
	return (str[i] == 0);
}

void	ft_echo(char **args, int fd)
{
	int		i;
	bool	n_flag;

	i = 0;
	n_flag = false;
	while (args[i] && is_n_option(args[i]))
	{
		n_flag = true;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], fd);
		if (args[i + 1])
			ft_putchar_fd(' ', fd);
		i++;
	}
	if (!n_flag)
		ft_putchar_fd('\n', fd);
}
