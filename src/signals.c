/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:04:37 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/11 17:26:56 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inc.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	set_signal_printing(void)
{
	struct termios	new_term;

	tcgetattr(0, &new_term);
	new_term.c_lflag &= ~(ISIG | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
}
