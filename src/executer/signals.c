/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:04:37 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/07/10 17:57:29 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigint_handler(int sigint)
{

	// rl_on_new_line, rl_replace_line, rl_redisplay
	// tcsetattr, tcgetattr
	//ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sigint;
}


void	set_signal_printing(void)
{
	struct termios	ter_attr;
	int				fd;

	fd = STDIN_FILENO;
	tcgetattr(fd, &ter_attr);
	//change terminal attributes

	tcsetattr(fd, TCSANOW, &ter_attr);
}

