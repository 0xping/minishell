/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:16:59 by m-boukel          #+#    #+#             */
/*   Updated: 2023/07/30 02:42:49 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo_print(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			if (str[i + 1] == 'n')
				ft_putchar_fd('\n', fd);
			if (str[i + 1] == 't')
				ft_putchar_fd('\t', fd);
			i += 2;
		}
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

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
		echo_print(args[i], fd);
		if (args[i + 1])
			ft_putchar_fd(' ', fd);
		i++;
	}
	if (!n_flag)
		ft_putchar_fd('\n', fd);
}

// int	main(int argc, char const *argv[])
// {
// 	char	**d;

// 	d = ft_split("-nn -nnnnnn hello -n ", ' ');
// 	ft_echo(d, 1);
// 	return (0);
// }
