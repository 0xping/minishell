/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:57:55 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/14 15:11:21 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

int	check_sign(int lent, char **cmd)
{
	int	i;

	i = 0;
	while (i < lent)
	{
		if (cmd[i][0] == '-' || cmd[i][0] == '+')
			return (1);
		i++;
	}
	return (0);
}

int	check_int_range(char *av)
{
	if (ft_atoi(av) > INT_MAX)
		return (1);
	else if (ft_atoi(av) < INT_MIN)
		return (-1);
	return (0);
}

void	exit_with_sign(char **cmd)
{
	if (cmd[1][0] == '-' && cmd[1][1] == '-')
		exit(0);
	else if (cmd[1][1] == '\0' || cmd[1][1] == '+' || (cmd[1][0] == '+'
			&& cmd[1][1] == '-'))
	{
		write(2, "Minishell: exit: ", 17);
		write(2, cmd[1], ft_strlen(cmd[1]));
		write(2, ": numeric argument required\n", 28);
		exit(255);
	}
}

void	exit_with_non_digit(char **cmd)
{
	write(2, "Minishell: exit: ", 17);
	write(2, cmd[1], ft_strlen(cmd[1]));
	write(2, ": numeric argument required\n", 28);
	exit(255);
}

void	ft_exit(char **cmd)
{
	int	count;
	int	j;
	int	lent;

	count = 0;
	lent = 0;
	j = 0;
	while (cmd[lent])
		lent++;
	if (lent == 1)
		exit(0);
	else if (check_sign(2, cmd))
		exit_with_sign(cmd);
	j = 1;
	if (lent >= 1)
	{
		while (cmd[1][j])
			if (!('0' <= cmd[1][j] && cmd[1][j++] <= '9'))
				exit_with_non_digit(cmd);
		if (lent > 2)
			write(2, "Minishell: exit: too many arguments\n", 37);
		else if (count == 0)
			exit(ft_atoi(cmd[1]));
	}
}
